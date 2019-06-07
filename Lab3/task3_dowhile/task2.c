#include <math.h>
#include "func.h"

double summ2(double eps)
{
    double a = 0;
    double s = 0;
    int i = 0;

	do
	{
	    a = pow(-1,i)*((double)(2*(i+1))/(double)(2+(i+1)*(i-1)));
        if (fabs(a) <= eps)
        {
            return s;
        }
	    s += a;
	    ++i;
	} while (1);
}
