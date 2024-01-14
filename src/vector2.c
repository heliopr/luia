#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "vector2.h"

vector2 vector2_mult(vector2 v1, double n) {
    vector2 r = {v1.x * n, v1.y * n};
    return r;
}

vector2 vector2_sum(vector2 v1, vector2 v2) {
    vector2 r = {v1.x + v2.x, v1.y + v2.y};
    return r;
}

vector2 vector2_sub(vector2 v1, vector2 v2) {
    vector2 r = {v1.x - v2.x, v1.y - v2.y};
    return r;
}

double vector2_dot(vector2 v1, vector2 v2) {
    return (v1.x*v2.x) + (v1.y*v2.y);
}

double vector2_magnitude(vector2 v) {
    return sqrt((v.x*v.x) + (v.y*v.y));
}

vector2 vector2_normalize(vector2 v) {
    return vector2_mult(v, 1/vector2_magnitude(v));
}