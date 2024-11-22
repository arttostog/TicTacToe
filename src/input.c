#include <input.h>

_Bool set_position(vector2_t* position) {
    printf("X Y: ");
    if (!scanf("%hhd %hhd", &position->x, &position->y)) abort();
    if (position->x > 2 || position->y > 2) return 1;
    return 0;
}