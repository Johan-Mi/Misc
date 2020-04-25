#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>

#include "piece.h"
#include "board.h"

extern u8 const tileCoordinates[29][4][2];

void drawTile(u8, u8, u8);
void drawBoard(Board);
void drawPiece(Piece);
void drawGhost(Board, Piece);

SDL_Surface* tileAtlas = NULL;
SDL_Surface* screen = NULL;

int speed = 4000;

u8 bag = 0;

int main(void) {
	bool quit = false;
	bool paused = false;

	Board board;
	Piece piece;

	SDL_Event event;

	u64 timer = 0;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_EnableKeyRepeat(230, 35);
	screen = SDL_SetVideoMode(SCREEN_WIDTH,
			SCREEN_HEIGHT,
			32,
			SDL_SWSURFACE);
	tileAtlas = SDL_LoadBMP("gfx/tileAtlas.bmp");

	srand(time(NULL));

	randomizeBoard(board, 0, 0);
	piece = randomPiece();

	drawTile(6, 0, 0);
	drawTile(7, BOARD_WIDTH + 1, 0);
	drawTile(8, 0, BOARD_HEIGHT - HIDDEN_ROWS + 1);
	drawTile(9, BOARD_WIDTH + 1, BOARD_HEIGHT - HIDDEN_ROWS + 1);
	for(u8 i = 1; i <= BOARD_WIDTH; i++) {
		drawTile(5, i, 0); //Top edge
		drawTile(4, i, BOARD_HEIGHT - HIDDEN_ROWS + 1); //Bottom edge
	}
	for(u8 i = 1; i <= BOARD_HEIGHT - HIDDEN_ROWS; i++) {
		drawTile(2, 0, i); //Left edge
		drawTile(3, BOARD_WIDTH + 1, i); //Right edge
	}

	while(!quit) {
		while(SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT:
					quit = true;
					break;
				case SDL_KEYDOWN:
					if(event.key.keysym.sym == SDLK_p) {
							paused = !paused;
					}
					if(!paused) {
						switch(event.key.keysym.sym) {
							case SDLK_ESCAPE:
								quit = true;
								break;
							case SDLK_a:
								tryMoveLeft(board, &piece);
								break;
							case SDLK_d:
								tryMoveRight(board, &piece);
								break;
							case SDLK_s:
								tryMoveDown(board, &piece);
								break;
							case SDLK_LCTRL:
							case SDLK_x:
								tryRotLeft(board, &piece);
								break;
							case SDLK_w:
							case SDLK_c:
								tryRotRight(board, &piece);
								break;
							case SDLK_SPACE:
								tryDrop(board, &piece);
								break;
							default:
								break;
						}
					}
					break;
				default:
					break;
			}
		}

		if(paused)
			continue;

		timer++;
		if(!(timer % speed))
			tryMoveDown(board, &piece);

		drawBoard(board);
		drawGhost(board, piece);
		drawPiece(piece);

		SDL_Flip(screen);
	}

	SDL_Quit();
	return EXIT_SUCCESS;
}

void drawTile(u8 color, u8 x, u8 y) {
	SDL_BlitSurface(tileAtlas,
			&(SDL_Rect){ TILE_SIZE * color, 0, TILE_SIZE, TILE_SIZE },
			screen,
			&(SDL_Rect){ .x = TILE_SIZE * x, .y = TILE_SIZE * y});
}

void drawBoard(Board board) {
	for(int i = 0; i < BOARD_HEIGHT - HIDDEN_ROWS; i++) {
		for(int j = 0; j < BOARD_WIDTH; j++) {
			drawTile(board[i + HIDDEN_ROWS][j], j + 1, i + 1);
		}
	}
}

void drawPiece(Piece piece) {
	u8 color = colorOfPiece(piece);

	for(u8 i = 0; i < 4; i++) {
		u8 x = piece.x + tileCoordinates[piece.shape][i][0];
		u8 y = piece.y + tileCoordinates[piece.shape][i][1];
		if(y >= HIDDEN_ROWS)
			drawTile(color, x + 1, y + 1 - HIDDEN_ROWS);
	}
}

void drawGhost(Board board, Piece piece) {
	do {
		piece.y++;
	} while(!pieceCollides(board, piece));
	piece.y--;

	for(u8 i = 0; i < 4; i++) {
		u8 x = piece.x + tileCoordinates[piece.shape][i][0];
		u8 y = piece.y + tileCoordinates[piece.shape][i][1];
		if(y >= HIDDEN_ROWS)
			drawTile(1, x + 1, y + 1 - HIDDEN_ROWS);
	}
}
