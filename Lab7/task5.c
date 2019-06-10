#include <stdio.h>
#include <math.h>

char *strcat(const char *first, const char *second)
{
	int n = strlen(first) + strlen(second) + 1;
	char *dest = (char*) malloc(n);
	char *d = dest;
	const char *f = first;
	const char *s = second;
	int dlen;

	while (*f != '\0')
	{
	    *d++ = *f;
		f++;
	}

	while (*s != '\0')
	{
	    *d++ = *s;
		s++;
	}
	*d = '\0';

	return dest;
}
/*
void main()
{
    const char *first = "Calling";
    const char *second = "you";

    printf("string1: \"%s\"\n\n", first);
    printf("string2: \"%s\"\n\n", second);

    char *dest = strcat(first, second);
    printf("dest after cat:  \"%s\"\n", dest);

    system("pause");
    return 0;
}*/
