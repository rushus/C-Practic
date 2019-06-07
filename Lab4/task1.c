#include <stdio.h>
#include <math.h>

void f(const double *x, double *result)
{
    *result = pow(cos(*x), 2)+pow(cos(*x), 4);
}
