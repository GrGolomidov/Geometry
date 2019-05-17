#ifndef CALCULATION_H
#define CALCULATION_H

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

struct pointer {
    double x;
    double y;
};

struct figure_circle {
    pointer vertex;
    double radius;
};

const double PI = 3.1415926535;
double perimetr_circle(figure_circle circle, const double PI);
double square_circle(figure_circle circle, const double PI);

#endif
