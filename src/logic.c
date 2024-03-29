#include "logic.h"

char _movesCount = 0;

_Bool _setMatrix(pos* position, char matrix[][3], char symbol, _Bool* crosses) {
    char* pointer = &matrix[position->x][position->y];
    if (*pointer == ' ') {
        *pointer = symbol;
        *crosses = !*crosses;
        return 1;
    }
    return 0;
}

void _checkWinner(char* winner, char matrix[][3], char symbol) {
    for (char i = 0; i < 3; ++i) {
        if (matrix[i][0] == symbol && matrix[i][1] == symbol && matrix[i][2] == symbol ||
            matrix[0][i] == symbol && matrix[1][i] == symbol && matrix[2][i] == symbol) {
            *winner = symbol;
            return;
        }
    }

    if (matrix[1][1] == symbol) {
        if (matrix[0][0] == symbol && matrix[2][2] == symbol ||
            matrix[2][0] == symbol && matrix[0][2] == symbol) {
            *winner = symbol;
            return;
        }
    }
    
    if (++_movesCount < 9) return;
    
    *winner = '!';
}

void doLogic(char* winner, pos* position, char matrix[][3], char symbol, _Bool* crosses) { 
    if (setPosition(position)) return;
    if (_setMatrix(position, matrix, symbol, crosses))
        _checkWinner(winner, matrix, symbol);
}