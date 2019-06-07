#include <stdio.h>
#include <stdlib.h>

void incrementHeapVariable()
{
    int *p = (int *) malloc(sizeof(int));
    printf("Input num:\n");
    scanf("%d", p);
    printf("%p : %d\n", p, *p);
    *p += 1;
    printf("%p : %d\n", p, *p);
    free(p);
}

void main()
{
    incrementHeapVariable();

    system("pause");
    return 0;
}
