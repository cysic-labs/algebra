#ifndef POINT_ADD
#define POINT_ADD

#include<stdint.h>
typedef struct point_projective_t {
    uint64_t x[6];
    uint64_t y[6];
    uint64_t z[6];
} point_projective_t;

void point_add(
    const point_projective_t *a,
    const point_projective_t *b,
    point_projective_t *res
);


// Credit: https://stackoverflow.com/questions/7775991/how-to-get-hexdump-of-a-structure-data
void hexDump(const char *desc, const void *addr, const int len);

#endif // POINT_ADD