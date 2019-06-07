#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char *strcpy(const char *src)
{
	char *dest = (char*) malloc(sizeof(src));
	char *d = dest;
    while ((*dest++ = *src++) != '\0');

    return d;
}

void main()
{
    const char *str = "string example";

    printf("string: \"%s\"\n\n", str);

    char *dest = strcpy(str);

    printf("dest after copy:  \"%s\"\n", dest);

    system("pause");
    return 0;
}
