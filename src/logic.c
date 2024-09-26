#include "logic.h"

vector2_t _position;
char _movesCount = 1;

_Bool _set_matrix(char gameField[3][3], char symbol) {
    char* pointer = &gameField[_position.x][_position.y];
    if (*pointer != ' ') return 1;
    *pointer = symbol;
    return 0;
}

_Bool _equal(char* array, char size) {
    for (char symbol = array[0], i = 1; i < size; ++i)
        if (symbol != array[i]) return 0;
    return 1;
}

_Bool _check_three_in_a_row(char* winner, char gameField[3][3], char symbol) {
    for (char i = 0; i < 3; ++i) {
        char checkVertically[4] = {symbol, gameField[i][0], gameField[i][1], gameField[i][2]},
            checkHorizontally[4] = {symbol, gameField[0][i], gameField[1][i], gameField[2][i]};
        if (_equal(checkVertically, 4) || _equal(checkHorizontally, 4)) {
            *winner = symbol;
            return 1;
        }
    }
    return 0;
}

_Bool _check_cross(char* winner, char gameField[3][3], char symbol) {
    if (gameField[1][1] != symbol) return 0;
    char checkCross[3] = {symbol, gameField[0][0], gameField[2][2]},
        checkCross2[3] = {symbol, gameField[2][0], gameField[0][2]};
    if (_equal(checkCross, 3) || _equal(checkCross2, 3)) {
        *winner = symbol;
        return 1;
    }
    return 0;
}

void _checkWinner(char* winner, char gameField[3][3], char symbol) {
    if (_check_three_in_a_row(winner, gameField, symbol) ||
        _check_cross(winner, gameField, symbol) || ++_movesCount < 10) 
        return;
    *winner = '!';
}

void do_game_logic(char* winner, char gameField[3][3], char* symbol) {
    if (set_position(&_position) || _set_matrix(gameField, *symbol)) return;
    _checkWinner(winner, gameField, *symbol);
    *symbol = *winner ? *winner : *symbol == 'X' ? 'O' : 'X'; 
}