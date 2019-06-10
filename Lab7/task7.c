#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

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
    char *name;
    enum Marktype marktype;
    union Mark mark;
    struct tm date;
    char *teacherln;
};
//Семестр
struct Semester
{
    int number;
    int year;
	int subjectsCount;
    struct Subject *subjects;
};
//Зачетка
struct RecordBook
{
    char *firstName;
    char *middleName;
    char *lastName;
    int number;
	int semestersCount;
    struct Semester *semesters;
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
    for (int subId = 0; subId < semester->subjectsCount; ++subId)
    {
        printSubject(&semester->subjects[subId]);
    }
}

void fillSubject(struct Subject *subject, const char *name, 
	enum Marktype marktype, union Mark mark, struct tm date, 
	const char *teacherln)
{
	subject->name = (char*)malloc(sizeof(char) * 50);
	strcpy(subject->name, name);
	subject->marktype = marktype;
	subject->mark = mark;
	subject->date = date;
	subject->teacherln = (char*)malloc(sizeof(char) * 50);
	strcpy(subject->teacherln, teacherln);
}

void freeSubject(struct Subject *subject)
{
	free(subject->name);
	free(subject->teacherln);
}

void fillSemester1(struct Semester *semester)
{
	semester->number = 1;
	semester->year = 1;
	semester->subjectsCount = 2;
	semester->subjects = (struct Subject *) calloc(semester->subjectsCount, sizeof(struct Subject));
	union Mark physicsMark = {.acceptable = 1};
	struct tm physicsDate = { .tm_mday = 17, .tm_mon = 11, .tm_year = 2017 };
	fillSubject(&semester->subjects[0], "Physics", test, physicsMark, physicsDate, "Saveliev");
	union Mark mathMark = { .mark = good};
	struct tm mathDate = { .tm_mday = 20,.tm_mon = 0,.tm_year = 2018 };
	fillSubject(&semester->subjects[1], "Math", exam, mathMark, mathDate, "Euclid");
}

void fillSemester2(struct Semester *semester)
{
	semester->number = 2;
	semester->year = 1;
	semester->subjectsCount = 2;
	semester->subjects = (struct Subject *) calloc(semester->subjectsCount, sizeof(struct Subject));
	union Mark historyMark = { .acceptable = 1 };
	struct tm historyDate = { .tm_mday = 29,.tm_mon = 4,.tm_year = 2018 };
	fillSubject(&semester->subjects[0], "History", test, historyMark, historyDate, "Karamzin");
	union Mark philoMark = { .acceptable = 1 };
	struct tm philoDate = { .tm_mday = 3,.tm_mon = 5,.tm_year = 2018 };
	fillSubject(&semester->subjects[1], "Philosophy", test, philoMark, philoDate, "Aristotle");
}

void freeSemester(struct Semester *semester)
{
	for (int i = 0; i < semester->subjectsCount; i++)
		freeSubject(&semester->subjects[i]);
	free(semester->subjects);
}

int main()
{
    char *name = (char*) malloc(sizeof(char) * 50);
    char *teacherln = (char*)malloc(sizeof(char) * 20);
    char *firstName = (char*)malloc(sizeof(char) * 20);
    char *middleName = (char*)malloc(sizeof(char) * 20);
    char *lastName = (char*)malloc(sizeof(char) * 20);

    struct RecordBook recordBook =
    {
     "Ruslan", //first name
     "Valerievich", //middle name
     "Khusainov", //last name
     1717, //rb number
	 2, //semestersCount
	(struct Semester *) calloc(2, sizeof(struct Semester))
    };

	fillSemester1(&recordBook.semesters[0]);
	fillSemester2(&recordBook.semesters[1]);

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
	for (int i = 0; i < recordBook.semestersCount; i++)
		freeSemester(&recordBook.semesters[i]);
	free(recordBook.semesters);
	system("pause");
	return 0;
}

