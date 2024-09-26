#include <stdio.h>
#include "output.h"
#include "logic.h"

char symbol = 'X', winner = 0, gameField[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

int main()
{
    while(!winner) {
        print_menu(gameField, symbol);
        do_game_logic(&winner, gameField, &symbol);
    }
    print_menu(gameField, symbol);
    printf(winner == '!' ? "Draw%c\n" : "Winner is %c!\n", winner);
    return 0;
}