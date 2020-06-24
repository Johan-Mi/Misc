#!/usr/bin/env python3
"""This moudule lets you play four in a row."""

EMPTY = 0
RED = 1
WHITE = 2
FULL = 3


def print_board(board):
    """Prints a four in a row board."""
    print("\033[0m\033[2J\033[3J\033[;H┌───────┐")
    for i in range(6):
        print("│", end="")
        for j in range(7):
            if board[j][i] == EMPTY:
                print("\033[0m◯", end="")
            elif board[j][i] == RED:
                print("\033[31m●", end="")
            else:
                print("\033[37m●", end="")
        print("\033[0m│")
    print("└1234567┘\n")


def check_win(board, turn):
    """Checks if a player has won the game."""
    for i in range(6):
        for j in range(4):
            if all(board[j + k][i] == turn for k in range(4)):
                return turn
    for i in range(3):
        for j in range(7):
            if all(board[j][i + k] == turn for k in range(4)):
                return turn
        for j in range(4):
            if all(board[j + k][i     + k] == turn for k in range(4)) \
            or all(board[j + k][i + 3 - k] == turn for k in range(4)):
                return turn
    if not any(EMPTY in i for i in board):
        return FULL
    return None


def main():
    """Creates a board and lets two people play against each other."""
    board = []
    for _ in range(7):
        board.append([EMPTY] * 6)

    turn = WHITE

    while True:
        print_board(board)

        while True:
            try:
                x_pos = int(input("RED: " if turn == RED else "WHITE: "))
            except ValueError:
                continue
            if 0 < x_pos < 8:
                x_pos -= 1
                if board[x_pos][0] == EMPTY:
                    y_pos = board[x_pos].count(EMPTY) - 1
                    board[x_pos][y_pos] = turn
                    break
        res = check_win(board, turn)
        if res == turn:
            print_board(board)
            print("Red won!" if turn == RED else "White won!")
            break
        if res == FULL:
            print_board(board)
            print("Draw!")
            break
        turn = RED if turn == WHITE else WHITE


if __name__ == "__main__":
    main()
