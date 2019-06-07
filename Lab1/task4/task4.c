#include <stdio.h>
#include <math.h>

void f();
double x;
double result;

void main(){
	x=5;
	f();
	printf("x =  %.4lf\nf(x) = %.4lf", x, result);

	printf("\nEnter x:\n");
	scanf("%lf", &x);
	f();
	printf("x =  %.4lf\nf(x) = %.4lf\n", x, result);

	system("pause");
    return 0;
}

void f(){
	result = pow(cos(x), 2)+pow(cos(x), 4);
}
