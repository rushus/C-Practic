#include <math.h>

double f(double x){
	if (x<=3)
		return pow(x,2)+3*x+9;
	else
		return (sin(x))/(pow(x,2)-9);
}
