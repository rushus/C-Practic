#include <math.h>
#include "func.h"

int findFirstNegativeElement(double eps)
{
    double a = 0;
    int i = 0;

    while (1)
    {
        a = pow(-1,i)*((double)(2*(i+1))/(double)(2+(i+1)*(i-1)));

        if ((a < 0) && (fabs(a) <= eps))
        {
            return i+1;
        }

        ++i;
    }
}
