#include <stdio.h>
#include <math.h>

char *strcat(const char *first, const char *second)
{
	char *dest = (char*) malloc(sizeof(first)+sizeof(second));
	char *d = dest;
	const char *f = first;
	const char *s = second;
	int n = sizeof(dest);
	int dlen;

	while (*f != '\0')
	{
	    *d++ = *f;
		f++;
	}

	if (n == 0) {
		if (sizeof(dest) != 0)
			*d = '\0';
	}

	while (n-- != 0 && *d != '\0')
		d++;

	while (*s != '\0')
	{
	    *d++ = *s;
		s++;
	}
	*d = '\0';

	return dest;
}

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
}
