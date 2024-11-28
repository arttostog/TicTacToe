#include <stdio.h>
#include <output.h>
#include "logic.h"

char gameField[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
}, movesCount = 0, symbol = 'X', winner = 0;

int main()
{
    while(!winner) {
        print_menu(gameField, symbol);
        do_game_logic(gameField, &movesCount, &symbol, &winner);
    }
    print_menu(gameField, symbol);
    printf(winner == '!' ? "Draw%c\n" : "Winner is %c!\n", winner);
    return 0;
}