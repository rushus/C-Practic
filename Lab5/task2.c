#include <stdio.h>
#include <math.h>

char *find(const char *str, const char *substr)
{
    const char *temp, *c;
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


void main()
{
    char* index;
	const char* str = "hello";
	const char* substr = "el";
    if((index = find(str, substr)) == NULL)
       printf("0\n");
    else
       printf("Index = %s\n", index);

    system("pause");
    return 0;
}
