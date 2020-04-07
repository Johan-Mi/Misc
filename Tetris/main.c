#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>

#include "piece.h"
#include "board.h"

void drawTile(u8, u8, u8);
void drawBoard(Board);
void drawPiece(Piece);

SDL_Surface* tileAtlas = NULL;
SDL_Surface* screen = NULL;

int main(int argc, char *argv[]) {
	Board board;
	Piece piece;
;
	SDL_Event event;

	SDL_Init(SDL_INIT_EVERYTHING);
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE);

	tileAtlas = SDL_LoadBMP("gfx/tileAtlas.bmp");

	srand(time(NULL));

	randomizeBoard(board, 10, 10);
	piece = randomPiece();

	for(;;) {
		while(SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT:
					SDL_Quit();
					return EXIT_SUCCESS;
				case SDL_KEYDOWN:
					switch(event.key.keysym.sym) {
						case SDLK_ESCAPE:
							SDL_Quit();
							return EXIT_SUCCESS;
						case SDLK_a:
							tryMoveLeft(board, &piece);
							break;
						case SDLK_d:
							tryMoveRight(board, &piece);
							break;
						case SDLK_s:
							tryMoveDown(board, &piece);
							break;
						case SDLK_q:
							tryRotLeft(board, &piece);
							break;
						case SDLK_e:
							tryRotRight(board, &piece);
							break;
						default:
							break;
					}
					break;
				default:
					break;
			}
		}

		drawBoard(board);
		drawPiece(piece);

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

u8 const tileCoordinates[29][4][2] = {
	[O]  = {{1, 0}, {2, 0}, {1, 1}, {2, 1}},
	[I1] = {{0, 1}, {1, 1}, {2, 1}, {3, 1}},
	[I2] = {{2, 0}, {2, 1}, {2, 2}, {2, 3}},
	[I3] = {{0, 2}, {1, 2}, {2, 2}, {3, 2}},
	[I4] = {{1, 0}, {1, 1}, {1, 2}, {1, 3}},
	[T1] = {{1, 0}, {0, 1}, {1, 1}, {2, 1}},
	[T2] = {{1, 0}, {1, 1}, {2, 1}, {1, 2}},
	[T3] = {{0, 1}, {1, 1}, {2, 1}, {1, 2}},
	[T4] = {{1, 0}, {0, 1}, {1, 1}, {1, 2}},
	[J1] = {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
	[J2] = {{1, 0}, {2, 0}, {1, 1}, {1, 2}},
	[J3] = {{0, 1}, {1, 1}, {2, 1}, {2, 2}},
	[J4] = {{1, 0}, {1, 1}, {1, 2}, {2, 2}},
	[L1] = {{2, 0}, {0, 1}, {1, 1}, {2, 1}},
	[L2] = {{1, 0}, {1, 1}, {1, 2}, {2, 2}},
	[L3] = {{0, 1}, {1, 1}, {2, 1}, {0, 2}},
	[L4] = {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
	[S1] = {{1, 0}, {2, 0}, {0, 1}, {1, 1}},
	[S2] = {{1, 0}, {1, 1}, {2, 1}, {1, 1}},
	[S3] = {{1, 1}, {2, 1}, {0, 2}, {1, 2}},
	[S4] = {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
	[Z1] = {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
	[Z2] = {{2, 0}, {1, 1}, {2, 1}, {1, 2}},
	[Z3] = {{0, 1}, {1, 1}, {1, 2}, {2, 2}},
	[Z4] = {{1, 0}, {0, 1}, {1, 1}, {0, 2}},
};

void drawPiece(Piece piece) {
	u8 color = colorOfPiece(piece);

	for(u8 i = 0; i < 4; i++) {
		drawTile(color, piece.x + tileCoordinates[piece.shape][i][0], piece.y + tileCoordinates[piece.shape][i][1]);
	}
}
