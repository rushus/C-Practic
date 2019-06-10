#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char *strcpy(const char *src)
{
	char *dest = (char*) malloc(strlen(src)+1);
	char *d = dest;
	for (int i = 0; i < strlen(src) + 1; i++)
	{
		*d = src[i];
		d++;
	}
	//while ((*dest++ = *src++) != '\0');

    return dest;
}
/*
void main()
{
    const char *str = "string example";

    printf("string: \"%s\"\n\n", str);

    char *dest = strcpy(str);

    printf("dest after copy:  \"%s\"\n", dest);

    system("pause");
    return 0;
}*/
