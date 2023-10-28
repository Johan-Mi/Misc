#pragma once

#include <stdbool.h>

#include "board.h"
#include "definitions.h"
#include "shapes.h"

typedef struct {
    Shape shape;
    u8 x;
    u8 y;
} Piece;

void tryMoveLeft(Board, Piece *);
void tryMoveRight(Board, Piece *);
void tryMoveDown(Board, Piece *, Piece *);
void tryMoveUp(Board, Piece *);
void tryRotLeft(Board, Piece *);
void tryRotRight(Board, Piece *);
void tryDrop(Board, Piece *, Piece *);
bool pieceCollides(Board, Piece);
void placePiece(Board, Piece *, Piece *);
u8 colorOfPiece(Piece);
Piece randomPiece(void);
