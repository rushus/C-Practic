#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

char *insert(const char *src, const char *str, int index)
{
    char *dest = (char*) malloc(strlen(src)+strlen(str) + 1);
	char*  t = dest;
	int k = 0;

	while (k < index)
	{
	    *t++ = *src;
		src++;
		k += 1;
	}

	while (*str != '\0')
	{
	    *t++ = *str;
		str++;
	}

	while (*src != '\0')
	{
	    *t++ = *src;
		src++;
	}
	*t++ = '\0';
	return dest;
}

void main(){
	const char *s = "BEGIN()END";

	const char *w = " * * * MOSCOW * * * ";
	int index = 6;

	printf("string: \"%s\"\n\n", s);

    char *dest = insert(s, w, index);
    printf("dest after insert:  \"%s\"\n", dest);


    system("pause");
	return 0;
}
