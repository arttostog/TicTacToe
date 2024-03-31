#include <stdio.h>
#include "output.h"
#include "logic.h"

char symbol = 'X', winner = 0, matrix[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

int main()
{
    while(!winner) {
        printMenu(matrix, symbol);
        doLogic(&winner, matrix, &symbol);
    }
    printMenu(matrix, symbol);
    printf(winner == '!' ? "Draw%c\n" : "Winner is %c!\n", winner);
    return 0;
}