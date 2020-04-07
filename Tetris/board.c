#include <stdlib.h>
#include <string.h>

#include "board.h"

void randomizeBoard(Board board, u8 filledLines, u8 density) {
	memset(board, 0, BOARD_WIDTH * (BOARD_HEIGHT - filledLines));

	for(u8 i = BOARD_HEIGHT - filledLines; i < BOARD_HEIGHT; i++) {
		for(u8 j = 0; j < BOARD_WIDTH; j++)
			board[i][j] = rand() % MAX_DENSITY < density ? rand() % 3 + 1 : 0;
		board[i][rand() % BOARD_WIDTH] = 0;
	}
}
