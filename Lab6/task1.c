#include <stdio.h>
#include <time.h>
#include <string.h>

//Оценка
enum Markvalue
{
    not_acceptable,
    acceptable,
    good,
    very_good
};

union Mark
{
    int acceptable;
    enum Markvalue mark;
};

//Предмет
enum Marktype
{
    test,
    exam
};

struct Subject
{
    char name[50];
    enum Marktype marktype;
    union Mark mark;
    struct tm date;
    char teacherln[20];
};
//Семестр
struct Semester
{
    int number;
    int year;
    struct Subject subjects[20];
};
//Зачетка
struct RecordBook
{
    char firstName[20];
    char middleName[20];
    char lastName[20];
    int number;
    struct Semester semesters[12];
};

void printRb(const struct RecordBook *recordBook)
{
    printf("============================\n");
    printf("FirstName: %s\nMiddleName: %s\nLastName: %s\n", recordBook->firstName, recordBook->middleName, recordBook->lastName);
    printf("RB number: %d\n\n", recordBook->number);
}

void printSubject(const struct Subject *subject)
{
    printf("%s | ", subject->name);
    printf("%s | ", (subject->marktype == test ? "test": "exam"));
    if (subject->marktype == test)
        printf("%s | ", subject->mark.acceptable ? "Passed": "Not Passed");
    else
    {
        switch(subject->mark.mark)
        {
            case not_acceptable:
                printf("%s | ", "Not Passed");
                break;
            case acceptable:
                printf("%s | ", "Passed");
                break;
            case good:
                printf("%s | ", "Good");
                break;
            case very_good:
                printf("%s | ", "Very Good");
                break;
        }
    }
    printf("%d.%d.%d | ", subject->date.tm_mday, subject->date.tm_mon + 1, subject->date.tm_year);
    printf("%s\n", subject->teacherln);

}

void printSemester(const struct Semester *semester)
{
    printf("Semester number: %d\nStudy year: %d\n", semester->number, semester->year);
    printf("Name | Type | Mark | Date | Teacher\n");
    printf("----------------------------\n");
    for (int subId = 0; subId<20 && strlen(semester->subjects[subId].name); ++subId)
    {
        printSubject(&semester->subjects[subId]);
    }
}

int main()
{
    struct RecordBook recordBook =
    {
     "Ruslan", //first name
     "Valerievich", //middle name
     "Khusainov", //last name
     1717, //rb number
     {
         { //semester 1
           1, //sem number
           1, //study year
           {
               {
                 "Physics", //name
                 test, //marktype
                 { //mark
                    .acceptable = 1
                 },
                 { //date
                     .tm_mday = 17,
                     .tm_mon = 11,
                     .tm_year = 2017
                 },
                 "Saveliev" //teacherln
               },
               {
                 "Math", //name
                 exam, //marktype
                 { //mark
                    .mark = good
                 },
                 { //date
                     .tm_mday = 20,
                     .tm_mon = 0,
                     .tm_year = 2018
                 },
                 "Euclid" //teacherln
               }
           }
         },
         { //semester 2
           2, //sem number
           1, //study year
           {
               {
                 "History", //name
                 test, //marktype
                 { //mark
                    .acceptable = 1
                 },
                 { //date
                     .tm_mday = 29,
                     .tm_mon = 4,
                     .tm_year = 2018
                 },
                 "Karamzin" //teacherln
               },
               {
                 "Philosophy", //name
                 test, //marktype
                 { //mark
                    .acceptable = 1
                 },
                 { //date
                     .tm_mday = 3,
                     .tm_mon = 5,
                     .tm_year = 2018
                 },
                 "Aristotle" //teacherln
               }
           }
         }
     }
    };

    printf("1. Open record book\r\n2. Exit\r\n");
	char answer = _getch();
	int x;

	switch (answer)
	{
		case '1':
		    printRb(&recordBook);
			printf("Please, enter number of semester:\n");
			scanf("%d", &x);
			printf("============================\n");
			printSemester(&recordBook.semesters[x-1]);
			break;
        case '2':
            break;

		default:
			printf("Incorrect input.\n");
			break;
	}

	system("pause");
	return 0;
}
