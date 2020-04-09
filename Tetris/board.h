#pragma once

#include "definitions.h"

typedef u8 Board[BOARD_HEIGHT][BOARD_WIDTH];

void randomizeBoard(Board, u8, u8);
void clearFullRows(Board);
