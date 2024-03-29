#include <stdio.h>
#include "output.h"
#include "logic.h"

_Bool crosses = 1;
pos position;
char winner = ' ', symbol, matrix[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

int main()
{
    while(winner == ' ') {
        symbol = crosses ? 'X' : 'O';
        printMenu(matrix, symbol);
        doLogic(&winner, &position, matrix, symbol, &crosses);
    }
    printMenu(matrix, symbol);
    printf(winner == '!' ? "Draw%c\n" : "Winner is %c!\n", winner);
    return 0;
}