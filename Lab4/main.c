#include <stdio.h>
#include "func.h"

int main(void)
{
    double x = 5;
    double result;
    const int n = 6;
    int a[] = {1,2,3,4,5,6};
    int ab[n];
    int ac[]={4,3,6,2,1,5};
    int ad[n];
    do
    {
        system("cls");
        printf("1 - Task1\n2 - Task2\n3 - Task3\n4 - Task4\n5 - Task5\n6 - Exit\r\n");
        char answer = _getch();
        system("cls");
        switch (answer)
        {
        case '1':
            f(&x, &result);
	        printf("x =  %.4lf\nf(x) = %.4lf", x, result);

	        printf("\nEnter x:\n");
	        scanf("%lf", &x);
	        f(&x, &result);
	        printf("x =  %.4lf\nf(x) = %.4lf\n", x, result);
            break;
        case '2':
            writeArray(a, n);
            printf("\n");
            break;
        case '3':
            readArray(ab, n);
            printf("\n");
            break;
        case '4':
            sort(ac, n);
            printf("\n");
            break;
        case '5':
            fullsort(ad, n);
            printf("\n");
            break;
        case '6':
            return 0;
            break;
        default:
            printf("Invalid input\n");
            break;
        }

        system("pause");

    } while (1);
    return 0;
}
