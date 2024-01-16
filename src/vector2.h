#ifndef VECTOR2_H
#define VECTOR2_H

typedef struct vector2 {
    double x, y;
} vector2;

vector2 vector2_mult(vector2 v1, double n);
vector2 vector2_sum(vector2 v1, vector2 v2);
vector2 vector2_sub(vector2 v1, vector2 v2);
double vector2_dot(vector2 v1, vector2 v2);
double vector2_magnitude(vector2 v);
vector2 vector2_normalize(vector2 v);

#endif