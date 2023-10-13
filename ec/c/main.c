#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "point_add.h"

int main() {

    
    point_projective_t *a, *b, *c;
    a = malloc(sizeof(point_projective_t));
    b = malloc(sizeof(point_projective_t));
    c = malloc(sizeof(point_projective_t));


    memset(a->x, 0, 48);
    memset(a->y, 1, 48);
    memset(a->z, 2, 48);

    memset(b->x, 4, 48);
    memset(b->y, 5, 48);
    memset(b->z, 6, 48);

    point_add(a, b, c);

    printf("point c:");
    hexDump("x", c->x, 48);
    hexDump("y", c->y, 48);
    hexDump("z", c->z, 48);

    printf("hello world");

    return 0;
}