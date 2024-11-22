#include <output.h>

void print_menu(char gameField[3][3], char symbol) {
    if (symbol == '!') symbol = '-';
    printf("\n---%c---\n", symbol);
    for (char y = 0; y < 3; ++y) {
        for (char x = 0; x < 3; ++x)
            printf("|%c", gameField[x][y]);
        printf("|\n-------\n");
    }
    printf("\n");
}