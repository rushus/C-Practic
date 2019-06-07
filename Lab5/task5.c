#include <stdio.h>
#include <math.h>

void strcpy(char *dest, int len, const char *src)
{
	char *d = dest;
	const char *s = src;
	int n = len;

	if (n != 0) {
		while (--n != 0) {
			if ((*d++ = *s++) == '\0')
				break;
		}
	}

	if (n == 0) {
		if (len != 0)
			*d = '\0';
	}
}

void strcat(char *dest, int len, const char *first, const char *second)
{
	char *d = dest;
	const char *s = second;
	int n = len;
	int dlen;

	strcpy(dest, len, first);

	while (n-- != 0 && *d != '\0')
		d++;
	dlen = d - dest;
	n = len - dlen;

	while (*s != '\0') {
		if (n != 1) {
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
}

void main()
{
    const char *first = "calling";
    const char *second = "you";
    char  buf[10] = "";

    printf("string1: \"%s\"\n\n", first);
    printf("string2: \"%s\"\n\n", second);
    printf("buf before cat: \"%s\"\n", buf);

    strcat(buf, sizeof(buf), first, second);
    printf("buf after cat:  \"%s\"\n", buf);

    system("pause");
    return 0;
}
