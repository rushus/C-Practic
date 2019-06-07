#include <math.h>
#include "func.h"

double summ2(double eps)
{
    double a = 0;
    double s = 0;

	for (int i = 0; ; ++i)
	{
	    a = pow(-1,i)*((double)(2*(i+1))/(double)(2+(i+1)*(i-1)));
        if (fabs(a) <= eps)
        {
            return s;
        }
	    s += a;
	}
}
