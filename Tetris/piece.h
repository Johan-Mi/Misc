#pragma once

#include <stdbool.h>

#include "definitions.h"
#include "shapes.h"
#include "board.h"

typedef struct {
	Shape shape;
	u8 x;
	u8 y;
} Piece;

void tryMoveLeft(Board, Piece*);
void tryMoveRight(Board, Piece*);
void tryMoveDown(Board, Piece*);
void tryRotLeft(Board, Piece*);
void tryRotRight(Board, Piece*);
void tryDrop(Board, Piece*);
bool pieceCollides(Board, Piece);
