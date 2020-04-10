#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>

#define LENGTH(arr) (sizeof(arr) / sizeof((arr)[0]))

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480 

#define POINT_SIZE 5

#define MOVE_SPEED 0.005f
#define TURN_SPEED 0.003f
#define ZSCALE 500.0f

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

typedef struct {
	float x, y, z;
} float3d;

struct {
	float x, y, z;
	float rx, ry;
} cam;

float3d viewTransform(float3d p) {
	float x = p.x - cam.x;
	float y = p.y - cam.y;
	float z = p.z - cam.z;

	float const z2 = x * cosf(cam.ry) + z * sinf(cam.ry);
	x = z * cosf(cam.ry) - x * sinf(cam.ry);
	z = z2 * cosf(cam.rx) - y * sinf(cam.rx);
	y = z2 * sinf(cam.rx) + y * cosf(cam.rx);

	if(z == 0.0f)
		z = 0.0000001f;
	x *= ZSCALE / z;
	y *= ZSCALE / z;

	return (float3d){ x, y, z };
}

float3d const points[] = {
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

	cam.x = 0.5f;
	cam.y = 0.5f;
	cam.z = -3.0f;
	cam.rx = 0.0f;
	cam.ry = M_PI_2;

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("3D",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	while(!quit) {
		SDL_Event event;

		prevTime = currTime;
		currTime = SDL_GetPerformanceCounter();
		deltaTime = (float)((currTime - prevTime) * 1000.0f / (float)SDL_GetPerformanceFrequency());

		while(SDL_PollEvent(&event)) {
			if(event.type == SDL_QUIT) {
				quit = true;
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
		if(cam.rx > M_PI_2)
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

		SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xff);

		for(size_t i = 0; i < LENGTH(points); i++) {
			float3d dp = viewTransform(points[i]);
			if(dp.z > 0) {
				SDL_RenderFillRect(renderer, &(SDL_Rect){
						dp.x + SCREEN_WIDTH / 2 - POINT_SIZE / 2,
						SCREEN_HEIGHT / 2 - dp.y - POINT_SIZE / 2,
						POINT_SIZE,
						POINT_SIZE});
			}
		}

		for(size_t i = 0; i < LENGTH(lines); i++) {
			float3d p1 = viewTransform(points[lines[i][0]]);
			float3d p2 = viewTransform(points[lines[i][1]]);
			if(p1.z > 0 || p2.z > 0) {
				if(p1.z < 0 || p2.z < 0) {
					if(p2.z < 0) {
						float3d const swp = p1;
						p1 = p2;
						p2 = swp;
					}
					float const f = p1.z / (p2.z - p1.z);
					p1 = (float3d){
						(p1.x * f - p2.x * (f - 1.0f)) / (p2.z - p1.z),
						(p1.y * f - p2.y * (f - 1.0f)) / (p2.z - p1.z),
						0
					};
				}
				SDL_RenderDrawLine(renderer,
						p1.x + SCREEN_WIDTH / 2,
						SCREEN_HEIGHT / 2 - p1.y,
						p2.x + SCREEN_WIDTH / 2,
						SCREEN_HEIGHT / 2 - p2.y);
			}
		}

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
};
