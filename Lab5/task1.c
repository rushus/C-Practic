#include <stdio.h>
#include <math.h>

int strlen(const char *str)
{
    int size = 0;
    while(*str++)
        ++size;
    return size;
}

void main()
{
	const char* str = "summer";
    printf("%d\n", strlen(str));

    system("pause");
    return 0;
}
