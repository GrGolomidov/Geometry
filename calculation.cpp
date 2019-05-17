#include "calculation.h"

double perimetr_circle(figure_circle circle, const double PI)
{
    return (2 * PI * circle.radius);
}

double square_circle(figure_circle circle, const double PI)
{
    return (PI * circle.radius * circle.radius);
}
