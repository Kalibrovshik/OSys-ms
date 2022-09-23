#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double overderive(double (*f)(double), double x0)
{
    const double delta = 1.0e-6; // or similar
    double x1 = x0 - delta;
    double x2 = x0 + delta;
    double y1 = f(x1);
    double y2 = f(x2);
    return (y2 - y1) / (x2 - x1);
}
double head2(double number2) {
    double xon = exp(number2);
    double yon = sin(number2);
    return xon * yon;
}