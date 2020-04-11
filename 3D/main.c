#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <GL/gl.h>

#include "types.h"

#define LENGTH(arr) (sizeof(arr) / sizeof((arr)[0]))

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480 

#define MOVE_SPEED 5.0f
#define TURN_SPEED 3.0f

Float3d viewTransform(Float3d);
bool zClipLine(Float3d*, Float3d*);

Camera cam;

Float3d const points[] = {
	{ 0, 0, 0 },
	{ 0, 0, 1 },
	{ 0, 1, 0 },
	{ 0, 1, 1 },
	{ 1, 0, 0 },
	{ 1, 0, 1 },
	{ 1, 1, 0 },
	{ 1, 1, 1 },
};

size_t const lines[][2] = {
	{ 0, 1 },
	{ 0, 2 },
	{ 1, 3 },
	{ 2, 3 },
	{ 0, 4 },
	{ 1, 5 },
	{ 2, 6 },
	{ 3, 7 },
	{ 4, 5 },
	{ 4, 6 },
	{ 5, 7 },
	{ 6, 7 },
};

int main(void) {
	bool quit = false;

	Uint64 currTime = SDL_GetPerformanceCounter();
	Uint64 prevTime = 0;
	float deltaTime = 0;

	Uint8 const *keys = SDL_GetKeyboardState(NULL);

	SDL_Window *window = NULL;
	SDL_GLContext glcontext;

	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("3D",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_OPENGL);
	glcontext = SDL_GL_CreateContext(window);
	
	cam.x = 0.5f;
	cam.y = 0.5f;
	cam.z = -3.0f;
	cam.rx = 0.0f;
	cam.ry = M_PI_2;

	SDL_GL_SetSwapInterval(1);

	glPointSize(5);
	glClearColor(0xff, 0xff, 0xff, 0xff);
	glColor3b(0x00, 0x00, 0x00);

	while(!quit) {
		SDL_Event event;

		prevTime = currTime;
		currTime = SDL_GetPerformanceCounter();
		deltaTime = (float)((currTime - prevTime)
				/ (float)SDL_GetPerformanceFrequency());

		while(SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT:
					quit = true;
					break;
				case SDL_KEYDOWN:
					switch(event.key.keysym.sym) {
						case SDLK_ESCAPE:
							quit = true;
							break;
						default:
							break;
					}
					break;
				default:
					break;
			}
		}

		if(keys[SDL_SCANCODE_L])
			cam.ry += TURN_SPEED * deltaTime;
		if(keys[SDL_SCANCODE_H])
			cam.ry -= TURN_SPEED * deltaTime;
		if(keys[SDL_SCANCODE_K])
			cam.rx -= TURN_SPEED * deltaTime;
		if(keys[SDL_SCANCODE_J])
			cam.rx += TURN_SPEED * deltaTime;

		if(cam.rx < -M_PI_2)
			cam.rx = -M_PI_2;
		else if(cam.rx > M_PI_2)
			cam.rx = M_PI_2;

		if(keys[SDL_SCANCODE_W]) {
			cam.z += MOVE_SPEED * sinf(cam.ry) * deltaTime;
			cam.x += MOVE_SPEED * cosf(cam.ry) * deltaTime;
		}
		if(keys[SDL_SCANCODE_S]) {
			cam.z -= MOVE_SPEED * sinf(cam.ry) * deltaTime;
			cam.x -= MOVE_SPEED * cosf(cam.ry) * deltaTime;
		}
		if(keys[SDL_SCANCODE_A]) {
			cam.z -= MOVE_SPEED * cosf(cam.ry) * deltaTime;
			cam.x += MOVE_SPEED * sinf(cam.ry) * deltaTime;
		}
		if(keys[SDL_SCANCODE_D]) {
			cam.z += MOVE_SPEED * cosf(cam.ry) * deltaTime;
			cam.x -= MOVE_SPEED * sinf(cam.ry) * deltaTime;
		}
		if(keys[SDL_SCANCODE_E])
			cam.y += MOVE_SPEED * deltaTime;
		if(keys[SDL_SCANCODE_Q])
			cam.y -= MOVE_SPEED * deltaTime;

		glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glBegin(GL_POINTS);
		for(size_t i = 0; i < LENGTH(points); i++) {
			Float3d dp = viewTransform(points[i]);
			if(dp.z > 0) {
				glVertex2f(dp.x, dp.y * SCREEN_WIDTH / SCREEN_HEIGHT);
			}
		}
		glEnd();

		glBegin(GL_LINES);
		for(size_t i = 0; i < LENGTH(lines); i++) {
			Float3d p1 = viewTransform(points[lines[i][0]]);
			Float3d p2 = viewTransform(points[lines[i][1]]);

			if(zClipLine(&p1, &p2)) {
				glVertex2f(p1.x, p1.y * SCREEN_WIDTH / SCREEN_HEIGHT);
				glVertex2f(p2.x, p2.y * SCREEN_WIDTH / SCREEN_HEIGHT);
			}
		}
		glEnd();

		SDL_GL_SwapWindow(window);
	}

	SDL_GL_DeleteContext(glcontext);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
};

Float3d viewTransform(Float3d p) {
	float x = p.x - cam.x;
	float y = p.y - cam.y;
	float z = p.z - cam.z;

	float const z2 = x * cosf(cam.ry) + z * sinf(cam.ry);
	x = z * cosf(cam.ry) - x * sinf(cam.ry);
	z = z2 * cosf(cam.rx) - y * sinf(cam.rx);
	y = z2 * sinf(cam.rx) + y * cosf(cam.rx);

	if(z == 0.0f)
		z = 0.0000001f;
	x /= z;
	y /= z;

	return (Float3d){ x, y, z };
}

bool zClipLine(Float3d *p1, Float3d *p2) {
	float f;

	if(p1->z > 0.0f && p2->z > 0.0f)
		return true;
	if(p1->z <= 0.0f && p2->z <= 0.0f)
		return false;

	if(p2->z <= 0.0f) {
		Float3d *const swp = p1;
		p1 = p2;
		p2 = swp;
	}

	f = p1->z / (p2->z - p1->z);
	*p1 = (Float3d){
			(p1->x * f - p2->x * (f - 1.0f)) / (p2->z - p1->z),
			(p1->y * f - p2->y * (f - 1.0f)) / (p2->z - p1->z),
			0.0f
	};
	return true;
}
