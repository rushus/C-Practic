#include <stdio.h>
#include <math.h>
#include <string.h>

char *find(const char *str, const char *substr)
{
    const char *temp, *c, *k;
    temp = substr;
    while (*str)
    {
    c = str;
    while(*(str++) == *(substr++))
    {
       if (!(*substr))
       {
           return (char*)c;
       }
       if(!(*str))
       {
          return NULL;
       }
    }
    substr = temp;
    }

    return NULL;
}


void move(char *target, int targetLength, char *last, int lastLength)
{
    for (int pos = 0; pos < targetLength || pos < lastLength; pos++)
    {
        char temp = target[pos];
        target[pos] = last[pos];
        last[pos] = temp;
    }
}


void delete(char *str, const char *substr)
{
    char* index = find(str, substr);
    char* cc = index + strlen(substr);
    for (int pos = 0; pos < strlen(substr); pos++)
    {
        index[pos] = '\0';
    }
    move(index, strlen(substr), cc, strlen(cc) );
    return str;
}


void main()
{
    char* index;
    char str[] = "winter";
	const char* substr = "in";
    if((index = find(str, substr)) == NULL)
       printf("0\n");
    else
       delete(str, substr);
       printf("%s\n", str);

    system("pause");
    return 0;
}
