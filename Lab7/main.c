#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	char str[] = "winter";
	const char* substr = "in";
	const char *str2 = "string example";
	const char *first = "calling";
	const char *second = "you";

	char* index;

	char s[] = "BEGIN()END";
	char w[] = " * * * MOSCOW * * * ";

	int p = 6;

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
			if ((index = find(str, substr)) == NULL)
				printf("0\n");
			else
			{
				char* strheap = delete(str, substr);
				printf("%s\n", strheap);

			}

			break;
		case '4':
			printf("string: \"%s\"\n\n", str2);

			char *dest1 = strcpy(str2);

			printf("dest after copy:  \"%s\"\n", *dest1);

			break;
		case '5':
			printf("string1: \"%s\"\n\n", first);
			printf("string2: \"%s\"\n\n", second);

			char *dest2 = strcat(first, second);
			printf("dest after cat:  \"%s\"\n", dest2);

			break;
		case '6':
			printf("string: \"%s\"\n\n", s);

			char *dest3 = insert(s, w, p);
			printf("dest after insert:  \"%s\"\n", dest3);

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
