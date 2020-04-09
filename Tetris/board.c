#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "board.h"

void randomizeBoard(Board board, u8 filledLines, u8 density) {
	memset(board, 0, BOARD_WIDTH * (BOARD_HEIGHT - filledLines));

	for(u8 i = BOARD_HEIGHT - filledLines; i < BOARD_HEIGHT; i++) {
		for(u8 j = 0; j < BOARD_WIDTH; j++)
			board[i][j] = rand() % MAX_DENSITY < density ? rand() % 3 + 1 : 0;
		board[i][rand() % BOARD_WIDTH] = 0;
	}
}

void clearFullRows(Board board) {
	for(u8 i = 0; i < BOARD_HEIGHT; i++) {
		for(u8 j = 0; j < BOARD_WIDTH; j++)
			if(!board[i][j])
				goto not_full;
		memmove(&board[1], board, i * BOARD_WIDTH);
		memset(board, 0, BOARD_WIDTH);
not_full:;
	}
}
