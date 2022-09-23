#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

void defnothead() {
    double number;
    do {
        printf("Enter a double: ");
        scanf_s("%*c"); // burn stdin so as not to buffer up responses
    } while (1 != scanf_s("%lf", &number));
    double xin;
    xin = exp(number);
    xin = (double)abs(xin);
    xin = xin * -1;
    double yin = overderive(sin, number);
    printf("f (x)=exp(−modx)sin(x): %lf\n", yin * xin); // should be around 1.0
    double number2;
    do {
        printf("Enter a double: ");
        scanf_s("%*c"); // burn stdin so as not to buffer up responses
    } while (1 != scanf_s("%lf", &number2));
    printf("g(x)=exp(−modx)cos(x): %lf\n", head2(number2)); // should be around 1.0
}