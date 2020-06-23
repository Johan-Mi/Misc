#!/usr/bin/env python3

EMPTY = 0
RED = 1
WHITE = 2
FULL = 3


def print_board(board):
    print('\033[0m\033[2J\033[3J\033[;H┌───────┐')
    for i in range(6):
        print('│', end='')
        for j in range(7):
            if board[j][i] == EMPTY:
                print('\033[0m◯', end='')
            elif board[j][i] == RED:
                print('\033[31m●', end='')
            else:
                print('\033[37m●', end='')
        print('\033[0m│')
    print('└1234567┘\n')


def check_win(board, t):
    for i in range(6):
        for j in range(4):
            if all((board[j + k][i] == t for k in range(4))):
                return t
    for i in range(3):
        for j in range(7):
            if all((board[j][i + k] == t for k in range(4))):
                return t
        for j in range(4):
            if all((board[j + k][i     + k] == t for k in range(4))) \
            or all((board[j + k][i + 3 - k] == t for k in range(4))):
                return t
    if not any([EMPTY in i for i in board]):
        return FULL
    return None


def main():
    board = []
    for _ in range(7):
        board.append([EMPTY] * 6)

    turn = WHITE

    while True:
        print_board(board)

        while True:
            try:
                x = int(input('RED: ' if turn == RED else 'WHITE: '))
                if 0 < x < 8:
                    x -= 1
                    if board[x][0] == EMPTY:
                        y = 0
                        while y < 5 and board[x][y + 1] == EMPTY:
                            y += 1
                        board[x][y] = turn
                        break
            except ValueError:
                pass
        res = check_win(board, turn)
        if res == turn:
            print_board(board)
            print('RED won!' if turn == RED else 'WHITE won!')
            break
        if res == FULL:
            print_board(board)
            print('Draw!')
            break
        turn = RED if turn == WHITE else WHITE


if __name__ == "__main__":
    main()
