#include <stdio.h>
#include <math.h>

void main()
{
	double x = 5;
	double fx = pow(cos(x), 2)+pow(cos(x), 4);
	printf("x =  %.4lf\nf(x) = %.4lf", x, fx);

	printf("\nEnter x:\n");
	scanf("%lf", &x);
	fx = pow(cos(x), 2)+pow(cos(x), 4);
	printf("x =  %.4lf\nf(x) = %.4lf\n", x, fx);

	system("pause");
    return 0;
}
