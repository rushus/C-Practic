#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fullsort(int *arr, int n)
{
    printf("%d\n", n);
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
    printf("\n");
    int step = 1;
    int *temp = (int*)malloc(n * sizeof(temp));
    while (step < n)
    {
      int id = 0;
      int l = 0;
      int m = l + step;
      int r = l + step * 2;
      do
      {
        m = m < n ? m : n;
        r = r < n ? r : n;
        int i1 = l, i2 = m;
        for (; i1 < m && i2 < r; )
        {
          if (arr[i1] < arr[i2]) { temp[id++] = arr[i1++]; }
          else { temp[id++] = arr[i2++]; }
        }

        while (i1 < m) temp[id++] = arr[i1++];
        while (i2 < r) temp[id++] = arr[i2++];
        l += step * 2;
        m += step * 2;
        r += step * 2;
      } while (l < n);
      for (int i = 0; i < n; i++)
        arr[i] = temp[i];
      step *= 2;
    }

    for(i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
}
