#include "piece.h"

Shape const leftRotatorArray[] = {
	[O] = O,
	[I1] = I4,
	[I2] = I1,
	[I3] = I2,
	[I4] = I3,
	[T1] = T4,
	[T2] = T1,
	[T3] = T2,
	[T4] = T3,
	[J1] = J4,
	[J2] = J1,
	[J3] = J2,
	[J4] = J3,
	[L1] = L4,
	[L2] = L1,
	[L3] = L2,
	[L4] = L3,
	[S1] = S4,
	[S2] = S1,
	[S3] = S2,
	[S4] = S3,
	[Z1] = Z4,
	[Z2] = Z1,
	[Z3] = Z2,
	[Z4] = Z3,
};

Shape const rightRotatorArray[] = {
	[O] = O,
	[I1] = I2,
	[I2] = I3,
	[I3] = I4,
	[I4] = I1,
	[T1] = T2,
	[T2] = T3,
	[T3] = T4,
	[T4] = T1,
	[J1] = J2,
	[J2] = J3,
	[J3] = J4,
	[J4] = J1,
	[L1] = L2,
	[L2] = L3,
	[L3] = L4,
	[L4] = L1,
	[S1] = S2,
	[S2] = S3,
	[S3] = S4,
	[S4] = S1,
	[Z1] = Z2,
	[Z2] = Z3,
	[Z3] = Z4,
	[Z4] = Z1,
};

void tryMoveLeft(Board board, Piece* piece) {
	piece->x--;
	if(pieceCollides(board, *piece))
		piece->x++;
}

void tryMoveRight(Board board, Piece* piece) {
	piece->x++;
	if(pieceCollides(board, *piece))
		piece->x--;
}

void tryMoveDown(Board board, Piece* piece) {
	piece->y++;
	if(pieceCollides(board, *piece))
		piece->y--;
}

void tryRotLeft(Board board, Piece* piece) {
	piece->shape = leftRotatorArray[piece->shape];
	if(pieceCollides(board, *piece))
		piece->shape = rightRotatorArray[piece->shape];
}

void tryRotRight(Board board, Piece* piece) {
	piece->shape = rightRotatorArray[piece->shape];
	if(pieceCollides(board, *piece))
		piece->shape = leftRotatorArray[piece->shape];
}

void tryDrop(Board board, Piece* piece) {
	do {
		piece->y++;
	} while(!pieceCollides(board, *piece));
	piece->y--;
}

bool pieceCollides(Board board, Piece piece) {
	return false;
}
