#include <logic.h>

static _Bool set_matrix(char gameField[3][3], point_t position, char symbol) {
    char* pointer = &gameField[position.x][position.y];
    if (*pointer != ' ') return 1;
    *pointer = symbol;
    return 0;
}

static _Bool check_three_in_a_row(char gameField[3][3], char symbol, char* winner) {
    for (char i = 0; i < 3; ++i) {
        if (symbol == gameField[i][0] && symbol == gameField[i][1] && symbol == gameField[i][2]
            || symbol == gameField[0][i] && symbol == gameField[1][i] && symbol == gameField[2][i]) {
            *winner = symbol;
            return 1;
        }
    }
    return 0;
}

static _Bool check_crosses(char gameField[3][3], char symbol, char* winner) {
    if (gameField[1][1] != symbol)
        return 0;

    if (symbol == gameField[0][0] && symbol == gameField[2][2]
        || symbol == gameField[2][0] && symbol == gameField[0][2]) {
        *winner = symbol;
        return 1;
    }
    return 0;
}

static void check_winner(char gameField[3][3], char* movesCount, char symbol, char* winner) {
    if (check_three_in_a_row(gameField, symbol, winner) ||
        check_crosses(gameField, symbol, winner) || ++*movesCount < 9) 
        return;
    *winner = '!';
}

void do_game_logic(char gameField[3][3], char* movesCount, char* symbol, char* winner) {
    if (set_matrix(gameField, get_new_position(), *symbol)) return;
    check_winner(gameField, movesCount, *symbol, winner);
    *symbol = *winner ? *winner : *symbol == 'X' ? 'O' : 'X'; 
}