#include <stdio.h>
#include <math.h>

void readArray(int *arr, int n)
{
    int i;
    printf("Input %d elements:\n", n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }

}
