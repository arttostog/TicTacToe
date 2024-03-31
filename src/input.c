#include "input.h"

_Bool setPosition(pos* position) {
    printf("X Y: ");
    if (!scanf("%d %d", &position->x, &position->y)) abort();
    if (position->x > 2 || position->y > 2) return 1;
    return 0;
}