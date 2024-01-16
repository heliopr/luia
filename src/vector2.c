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

vector2 vector2_calc_pos(vector2 pos, vector2 size, vector2 px, vector2 rel) {
    return (vector2){pos.x + px.x + (size.x * rel.x), pos.y + px.y + (size.y * rel.y)};
    //return vector2_sum(pos, vector2_sum(px, (vector2){size.x * rel.x, size.y * rel.y}));
}

vector2 vector2_calc_size(vector2 size, vector2 px, vector2 rel) {
    return (vector2){px.x + (size.x*rel.x), px.y + (size.y*rel.y)};
}

vector2 vector2_calc_anchor(vector2 pos, vector2 size, vector2 anchor) {
    return (vector2){pos.x - (size.x * anchor.x), pos.y - (size.y * anchor.y)};
}