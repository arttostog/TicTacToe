#include "logic.h"

pos _position;
char _movesCount = 0;

_Bool _setMatrix(char matrix[3][3], char symbol) {
    char* pointer = &matrix[_position.x][_position.y];
    if (*pointer != ' ') return 0;
    *pointer = symbol;
    return 1;
}

_Bool _equal(char* array) {
    for (char symbol = array[0], i = 1; array[i] != '\0'; ++i)
        if (symbol != array[i]) return 0;
    return 1;
}

_Bool _checkThreeInARow(char* winner, char matrix[3][3], char symbol) {
    for (char i = 0; i < 3; ++i) {
        char checkVertically[4] = {symbol, matrix[i][0], matrix[i][1], matrix[i][2]},
            checkHorizontally[4] = {symbol, matrix[0][i], matrix[1][i], matrix[2][i]};
        if (_equal(checkVertically) || _equal(checkHorizontally)) {
            *winner = symbol;
            return 1;
        }
    }
    return 0;
}

_Bool _checkCross(char* winner, char matrix[3][3], char symbol) {
    if (matrix[1][1] != symbol) return 0;
    char checkCross[3] = {symbol, matrix[0][0], matrix[2][2]},
        checkCross2[3] = {symbol, matrix[2][0], matrix[0][2]};
    if (_equal(checkCross) || _equal(checkCross2)) {
        *winner = symbol;
        return 1;
    }
    return 0;
}

void _checkWinner(char* winner, char matrix[3][3], char symbol) {
    if (_checkThreeInARow(winner, matrix, symbol) ||
        _checkCross(winner, matrix, symbol) || ++_movesCount < 9) return;
    *winner = '!';
}

void doLogic(char* winner, char matrix[3][3], char* symbol) { 
    if (setPosition(&_position) || !_setMatrix(matrix, *symbol)) return;
    _checkWinner(winner, matrix, *symbol);
    *symbol = *winner ? *winner : *symbol == 'X' ? 'O' : 'X'; 
}