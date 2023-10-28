#include <stdlib.h>

#include "piece.h"

Shape const leftRotatorArray[] = {
    [O] = O,   [I1] = I4, [I2] = I1, [I3] = I2, [I4] = I3, [T1] = T4, [T2] = T1,
    [T3] = T2, [T4] = T3, [J1] = J4, [J2] = J1, [J3] = J2, [J4] = J3, [L1] = L4,
    [L2] = L1, [L3] = L2, [L4] = L3, [S1] = S4, [S2] = S1, [S3] = S2, [S4] = S3,
    [Z1] = Z4, [Z2] = Z1, [Z3] = Z2, [Z4] = Z3,
};

Shape const rightRotatorArray[] = {
    [O] = O,   [I1] = I2, [I2] = I3, [I3] = I4, [I4] = I1, [T1] = T2, [T2] = T3,
    [T3] = T4, [T4] = T1, [J1] = J2, [J2] = J3, [J3] = J4, [J4] = J1, [L1] = L2,
    [L2] = L3, [L3] = L4, [L4] = L1, [S1] = S2, [S2] = S3, [S3] = S4, [S4] = S1,
    [Z1] = Z2, [Z2] = Z3, [Z3] = Z4, [Z4] = Z1,
};

u8 const tileCoordinates[29][4][2] = {
    [O] = {{1, 0}, {2, 0}, {1, 1}, {2, 1}},
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
    [J4] = {{1, 0}, {1, 1}, {0, 2}, {1, 2}},
    [L1] = {{2, 0}, {0, 1}, {1, 1}, {2, 1}},
    [L2] = {{1, 0}, {1, 1}, {1, 2}, {2, 2}},
    [L3] = {{0, 1}, {1, 1}, {2, 1}, {0, 2}},
    [L4] = {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
    [S1] = {{1, 0}, {2, 0}, {0, 1}, {1, 1}},
    [S2] = {{1, 0}, {1, 1}, {2, 1}, {2, 2}},
    [S3] = {{1, 1}, {2, 1}, {0, 2}, {1, 2}},
    [S4] = {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
    [Z1] = {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
    [Z2] = {{2, 0}, {1, 1}, {2, 1}, {1, 2}},
    [Z3] = {{0, 1}, {1, 1}, {1, 2}, {2, 2}},
    [Z4] = {{1, 0}, {0, 1}, {1, 1}, {0, 2}},
};

i8 const wallKicks[16][5][2] = {
    /* J L S T Z */
    {{0, 0}, {-1, 0}, {-1, 1}, {0, -2}, {-1, -2}},
    {{0, 0}, {1, 0}, {1, -1}, {0, 2}, {1, 2}},
    {{0, 0}, {1, 0}, {1, -1}, {0, 2}, {1, 2}},
    {{0, 0}, {-1, 0}, {-1, 1}, {0, -2}, {-1, -2}},
    {{0, 0}, {1, 0}, {1, 1}, {0, -2}, {1, -2}},
    {{0, 0}, {-1, 0}, {-1, -1}, {0, 2}, {-1, 2}},
    {{0, 0}, {-1, 0}, {-1, -1}, {0, 2}, {-1, 2}},
    {{0, 0}, {1, 0}, {1, 1}, {0, -2}, {1, -2}},

    /* I */
    {{0, 0}, {-2, 0}, {1, 0}, {-2, -1}, {1, 2}},
    {{0, 0}, {2, 0}, {-1, 0}, {2, 1}, {-1, -2}},
    {{0, 0}, {-1, 0}, {2, 0}, {-1, 2}, {2, -1}},
    {{0, 0}, {1, 0}, {-2, 0}, {1, -2}, {-2, 1}},
    {{0, 0}, {2, 0}, {-1, 0}, {2, 1}, {-1, -2}},
    {{0, 0}, {-2, 0}, {1, 0}, {-2, -1}, {1, 2}},
    {{0, 0}, {1, 0}, {-2, 0}, {1, -2}, {-2, 1}},
    {{0, 0}, {-1, 0}, {2, 0}, {-1, 2}, {2, -1}},
};

void tryMoveLeft(Board board, Piece *piece) {
    piece->x--;
    if (pieceCollides(board, *piece))
        piece->x++;
}

void tryMoveRight(Board board, Piece *piece) {
    piece->x++;
    if (pieceCollides(board, *piece))
        piece->x--;
}

void tryMoveDown(Board board, Piece *piece, Piece *nextPiece) {
    piece->y++;
    if (pieceCollides(board, *piece)) {
        piece->y--;
        placePiece(board, piece, nextPiece);
    }
}

void tryMoveUp(Board board, Piece *piece) {
    piece->y--;
    if (pieceCollides(board, *piece))
        piece->y++;
}

void tryRotLeft(Board board, Piece *piece) {
    int i;

    piece->shape = leftRotatorArray[piece->shape];

    switch (piece->shape) {
    case T1:
    case J1:
    case L1:
    case S1:
    case Z1:
        i = 1;
        break;
    case T2:
    case J2:
    case L2:
    case S2:
    case Z2:
        i = 3;
        break;
    case T3:
    case J3:
    case L3:
    case S3:
    case Z3:
        i = 5;
        break;
    case T4:
    case J4:
    case L4:
    case S4:
    case Z4:
        i = 7;
        break;
    case I1:
        i = 9;
        break;
    case I2:
        i = 11;
        break;
    case I3:
        i = 13;
        break;
    case I4:
        i = 15;
        break;
    case O:
        return;
    default:
        return;
    }

    for (u8 j = 0; j < 5; j++) {
        piece->x += wallKicks[i][j][0];
        piece->y -= wallKicks[i][j][1];
        if (pieceCollides(board, *piece)) {
            piece->x -= wallKicks[i][j][0];
            piece->y += wallKicks[i][j][1];
        } else {
            return;
        }
    }

    piece->shape = rightRotatorArray[piece->shape];
}

void tryRotRight(Board board, Piece *piece) {
    int i;

    piece->shape = rightRotatorArray[piece->shape];

    switch (piece->shape) {
    case T1:
    case J1:
    case L1:
    case S1:
    case Z1:
        i = 0;
        break;
    case T2:
    case J2:
    case L2:
    case S2:
    case Z2:
        i = 2;
        break;
    case T3:
    case J3:
    case L3:
    case S3:
    case Z3:
        i = 4;
        break;
    case T4:
    case J4:
    case L4:
    case S4:
    case Z4:
        i = 6;
        break;
    case I1:
        i = 8;
        break;
    case I2:
        i = 10;
        break;
    case I3:
        i = 12;
        break;
    case I4:
        i = 14;
        break;
    case O:
        return;
    default:
        return;
    }

    for (u8 j = 0; j < 5; j++) {
        piece->x += wallKicks[i][j][0];
        piece->y -= wallKicks[i][j][1];
        if (pieceCollides(board, *piece)) {
            piece->x -= wallKicks[i][j][0];
            piece->y += wallKicks[i][j][1];
        } else {
            return;
        }
    }

    piece->shape = leftRotatorArray[piece->shape];
}

void tryDrop(Board board, Piece *piece, Piece *nextPiece) {
    do {
        piece->y++;
    } while (!pieceCollides(board, *piece));
    piece->y--;
    placePiece(board, piece, nextPiece);
}

bool pieceCollides(Board board, Piece piece) {
    for (u8 i = 0; i < 4; i++) {
        if ((u8)(piece.x + tileCoordinates[piece.shape][i][0]) >= BOARD_WIDTH ||
            (u8)(piece.y + tileCoordinates[piece.shape][i][1]) >=
                BOARD_HEIGHT ||
            board[(u8)(piece.y + tileCoordinates[piece.shape][i][1])]
                 [(u8)(piece.x + tileCoordinates[piece.shape][i][0])]) {
            return true;
        }
    }

    return false;
}

void placePiece(Board board, Piece *piece, Piece *nextPiece) {
    u8 color = colorOfPiece(*piece);
    for (u8 i = 0; i < 4; i++)
        board[(u8)(piece->y + tileCoordinates[piece->shape][i][1])]
             [(u8)(piece->x + tileCoordinates[piece->shape][i][0])] = color;
    *piece = *nextPiece;
    *nextPiece = randomPiece();
    clearFullRows(board);
}

u8 colorOfPiece(Piece piece) {
    switch (piece.shape) {
    case O:
    case T1 ... T4:
    case I1 ... I4:
        return 13;
    case J1 ... J4:
    case S1 ... S4:
        return 14;
    case Z1 ... Z4:
    case L1 ... L4:
        return 15;
    default:
        return 0;
    }
}

Piece randomPiece(void) {
    extern u8 bag;

    if (bag == 0)
        bag = (1 << 7) - 1;

    for (;;) {
        u8 p = rand() % 7;
        if (bag & (1 << p)) {
            bag ^= 1 << p;
            return (Piece
            ){.x = BOARD_WIDTH / 2 - 2,
              .y = HIDDEN_ROWS,
              .shape = (Shape[]){O, I1, T1, J1, L1, S1, Z1}[p]};
        }
    }
}
