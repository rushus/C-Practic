#include <math.h>
#include "func.h"

extern double x, result;
extern void f(){
	result = pow(cos(x), 2)+pow(cos(x), 4);
}
