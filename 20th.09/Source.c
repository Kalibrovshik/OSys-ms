#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
double derive(double (*f)(double), double x0)
{
    const double delta = 1.0e-6; // or similar
    double x1 = x0 - delta;
    double x2 = x0 + delta;
    double y1 = f(x1);
    double y2 = f(x2);
    return (y2 - y1) / (x2 - x1);
}

// call it as follows:
void main(){
    double number;
    do{
        printf("Enter a double: ");
        scanf_s("%*c"); // burn stdin so as not to buffer up responses
    }while (1 != scanf_s("%lf", &number));
    double xin;
    xin = exp(number);
    xin = abs(xin);
    xin = xin * -1;
    double yin = derive(sin, number);
    //printf(" f (x)=exp(−∣x∣)sin(x): %lf\n", yin * xin); // should be around 1.0
    double number2;
    do {
        printf("Enter a double: ");
        scanf_s("%*c"); // burn stdin so as not to buffer up responses
    } while (1 != scanf_s("%lf", &number2));
    double xon = exp(number2);
    double yon = sin(number2);
   // printf(" g(x)=exp(−∣x∣)cos(x): %lf\n", xon * yon); // should be around 1.0
    ////////////////////////////////////////////dispersed solution
    defnothead();
}