#include <input.h>

point_t get_new_position() {
    printf("X Y: ");
    point_t position;
    if (!scanf("%d %d", &position.x, &position.y) || position.x > 2 || position.y > 2)
        abort();
    return position;
}