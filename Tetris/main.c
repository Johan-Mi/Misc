#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>

#include "piece.h"
#include "board.h"

extern u8 const tileCoordinates[29][4][2];

void drawTile(u8, u8, u8);
void drawBoard(Board);
void drawPiece(Piece);

SDL_Surface* tileAtlas = NULL;
SDL_Surface* screen = NULL;

int main(int argc, char *argv[]) {
	Board board;
	Piece piece;

	SDL_Event event;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_EnableKeyRepeat(350, 50);
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
						case SDLK_w:
							tryMoveUp(board, &piece);
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

void drawPiece(Piece piece) {
	u8 color = colorOfPiece(piece);

	for(u8 i = 0; i < 4; i++) {
		drawTile(color, piece.x + tileCoordinates[piece.shape][i][0], piece.y + tileCoordinates[piece.shape][i][1]);
	}
}
