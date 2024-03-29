#include "input.h"

_Bool setPosition(pos* position) {
    printf("X Y: ");
    if (!scanf("%hd %hd", &position->x, &position->y)) exit(1);
    if (position->x > 2 || position->y > 2) return 1;
    return 0;
}