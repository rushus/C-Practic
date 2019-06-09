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
/*
void main()
{
    const char *str = "string example";
    char  buf[10] = "";

    printf("string: \"%s\"\n\n", str);
    printf("buf before copy: \"%s\"\n", buf);

    strcpy(buf, sizeof(buf), str);

    printf("buf after copy:  \"%s\"\n", buf);

    system("pause");
    return 0;
}*/
