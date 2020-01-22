#!/usr/bin/env python3

Empty = 0
Red = 1
White = 2
Full = 3

board = []
for _ in range(7):
    board.append([Empty] * 5)

turn = White

def printBoard():
    print('\033[0m\033[2J\033[3J\033[;H┌───────┐')
    for i in range(5):
        print('│', end='')
        for j in range(7):
            if board[j][i] == Empty:
                print('\033[0m◯', end='')
            elif board[j][i] == Red:
                print('\033[31m●', end='')
            else:
                print('\033[37m●', end='')
        print('\033[0m│')
    print('└1234567┘\n')

def checkWin(t):
    for i in range(5):
        for j in range(4):
            if all((board[j + k][i] == t for k in range(4))):
                return t
    for i in range(7):
        for j in range(2):
            if all((board[i][j + k] == t for k in range(4))):
                return t
    for i in range(2):
        for j in range(4):
            if all((board[j + k][i + k] == t for k in range(4))):
                return t
    for i in range(3, 5):
        for j in range(4):
            if all((board[j + k][i - k] == t for k in range(4))):
                return t
    if not any([Empty in i for i in board]):
        return Full

while True:
    printBoard()

    while True:
        try:
            x = int(input('Red: ' if turn == Red else 'White: '))
            if x > 0 and x < 8:
                x -= 1
                if board[x][0] == Empty:
                    y = 0
                    while y < 4 and board[x][y + 1] == Empty:
                        y += 1
                    board[x][y] = turn
                    break
        except ValueError:
            pass
    res = checkWin(turn)
    if res == turn:
        printBoard()
        print('Red won!' if turn == Red else 'White won!')
        break
    elif res == Full:
        printBoard()
        print('Draw!')
        break
    turn = Red if turn == White else White
