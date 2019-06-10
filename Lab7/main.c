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
	char *dest;

	do
	{
		system("cls");
		printf("1 - Task1\n2 - Task2\n3 - Task3\n4 - Task4\n5 - Task5\n6 - Task6\n7 - Exit\r\n");
		char answer = _getch();
		system("cls");
		switch (answer)
		{
		case '1':
			incrementHeapVariable();

			break;
		case '2':
			sortHeapArray();
			printf("\n");

			break;
		case '3':
			if ((index = find(str3, substr2)) == NULL)
				printf("0\n");
			else
			{
				char* strheap = delete(str3, substr2);
				printf("%s\n", strheap);

			}

			break;
		case '4':
			printf("string: \"%s\"\n\n", str4);

			dest = strcpy(str4);

			printf("dest after copy:  \"%s\"\n", dest);

			break;
		case '5':
			printf("string1: \"%s\"\n\n", first);
			printf("string2: \"%s\"\n\n", second);

			dest = strcat(first, second);
			printf("dest after cat:  \"%s\"\n", dest);

			break;
		case '6':
			printf("string: \"%s\"\n\n", s);

			char *dest = insert(s, w, p);
			printf("dest after insert:  \"%s\"\n", dest);

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