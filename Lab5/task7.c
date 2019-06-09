#include <stdio.h>

void main(void)
{
	const char* str = "summer";
	const char* str2 = "hello";
	const char* substr = "el";
	char str3[] = "winter";
	const char* substr2 = "in";
	const char *str4 = "string example";
	const char *first = "calling";
	const char *second = "you";
	
	char* index;
	
	char buf[10] = "";
	char buf2[10] = "";
	char buf3[50] = "";
	
	char s[] = "BEGIN()END";
	char w[] = " * * * MOSCOW * * * ";
	
	int p = 6;
	int sl;

	do
	{
		system("cls");
		printf("1 - Task1\n2 - Task2\n3 - Task3\n4 - Task4\n5 - Task5\n6 - Task6\n7 - Exit\r\n");
		char answer = _getch();
		system("cls");
		switch (answer)
		{
		case '1':
			printf("%d\n", strlen(str));

			break;
		case '2':
			if ((index = find(str2, substr)) == NULL)
				printf("0\n");
			else
				printf("Index = %s\n", index);

			break;
		case '3':
			if ((index = find(str3, substr2)) == NULL)
				printf("0\n");
			else
				delete(str3, substr2);
			printf("%s\n", str3);

			break;
		case '4':
			printf("string: \"%s\"\n\n", str4);
			printf("buf before copy: \"%s\"\n", buf);

			strcpy(buf, sizeof(buf), str4);

			printf("buf after copy:  \"%s\"\n", buf);

			break;
		case '5':
			printf("string1: \"%s\"\n\n", first);
			printf("string2: \"%s\"\n\n", second);
			printf("buf before cat: \"%s\"\n", buf2);

			strcat(buf2, sizeof(buf2), first, second);
			printf("buf after cat:  \"%s\"\n", buf2);

			break;
		case '6':
			printf("string: \"%s\"\n\n", s);
			printf("buf before insert: \"%s\"\n", buf3);

			str_insert(s, w, p, buf3, sizeof(buf3));
			sl = strlen(buf3);
			if (sl < sizeof(buf3) && p < sizeof(s))
			{
				printf("buf after cat:  \"%s\"\n", buf3);
			}
			else {
				if (sl > sizeof(buf3)) {
					printf("sum str > buf");
				}
				if (p > sizeof(s)) {
					printf("index != str");
				}
			}

			break;
		case '7':
			return 0;
			break;
		default:
			printf("Invalid input\n");
			break;
		}

		system("pause");

	} while (1);
}