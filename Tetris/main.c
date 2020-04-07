#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>

#include "piece.h"
#include "board.h"

void drawTile(u8, u8, u8);
void drawBoard(Board);

SDL_Surface* tileAtlas = NULL;
SDL_Surface* screen = NULL;

int main(int argc, char *argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE);

	tileAtlas = SDL_LoadBMP("gfx/tileAtlas.bmp");

	srand(time(NULL));

	Board board;

	randomizeBoard(board, 10, 10);

	SDL_Event event;
	for(;;) {
		while(SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT:
					SDL_Quit();
					return EXIT_SUCCESS;
				default:
					break;
			}
		}

		drawBoard(board);

		SDL_Flip(screen);
	}

	SDL_Quit();
	return EXIT_SUCCESS;
}

void drawTile(u8 color, u8 x, u8 y) {
	SDL_BlitSurface(tileAtlas, &(SDL_Rect){ TILE_SIZE * color, 0, TILE_SIZE, TILE_SIZE }, screen, &(SDL_Rect){ TILE_SIZE * x, TILE_SIZE * y, TILE_SIZE, TILE_SIZE });
}

void drawBoard(Board board) {
	for(int i = 0; i < BOARD_HEIGHT; i++) {
		for(int j = 0; j < BOARD_WIDTH; j++) {
			drawTile(board[i][j], j, i);
		}
	}
}
