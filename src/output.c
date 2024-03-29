#include "output.h"

void printMenu(char matrix[][3], char symbol) {
    printf("\n---%c---\n", symbol);
    for (char y = 0; y < 3; ++y) {
        for (char x = 0; x < 3; ++x) {
            printf("|%c", matrix[x][y]);
        }
        printf("|\n-------\n");
    }
    printf("\n");
}