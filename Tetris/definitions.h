#pragma once

#include <stdint.h>

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 40
#define HIDDEN_ROWS 20

#define TILE_SIZE 16

#define SCREEN_WIDTH ((BOARD_WIDTH + 8) * TILE_SIZE)
#define SCREEN_HEIGHT ((BOARD_HEIGHT - HIDDEN_ROWS + 2) * TILE_SIZE)

#define MAX_DENSITY 20 /* Used for randomizeBoard() */

typedef uint8_t u8;
typedef int8_t i8;
typedef uint64_t u64;
