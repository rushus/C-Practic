#include <stdio.h>
#include <math.h>
#include <stdbool.h>


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

_Bool str_insert(const char *s, const char *w, int p, char *dest, int n)
{
	const char* q;
	int i, j;
	char*  t = dest;

	strcpy(dest, n, s);

	if((p >= n) || !*w)
		return false;

	for(q  = w; *q; ++q);
	for(dest += p; *dest; ++dest);

	i = (int)(q - w);
	j = (int)(dest - t);
	if((i + j) >= n)
		return false;

	dest += i;
	for(q = t + p; dest > q; --dest)
		*dest = *(dest - i);

	dest = t + p;
	while(*w)
		*dest++ = *w++;
	return true;
}

int main(void){
	char  buf[50] = "";
	char s[] = "BEGIN()END";

	char w[] = " * * * MOSCOW * * * ";
	int p = 6;
	int sl;

	printf("string: \"%s\"\n\n", s);
    printf("buf before insert: \"%s\"\n", buf);

    str_insert(s, w, p, buf, sizeof(buf));
    sl = strlen(buf);
    if (sl < sizeof(buf) && p < sizeof(s))
    {
        printf("buf after cat:  \"%s\"\n", buf);
    }
    else{
        if (sl > sizeof(buf)){
            printf("Сумма строк больше размера буфера");
        }
        if (p > sizeof(s)){
            printf("Индекс за пределами строки");
        }
    }

    system("pause");
	return 0;
}
