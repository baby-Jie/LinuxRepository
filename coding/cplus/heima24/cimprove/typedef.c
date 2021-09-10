#include <stdio.h>

typedef struct Student
{
	int age;
} Stu, *PStu;

int main()
{
	Stu stu;
	PStu ptr = &stu;
	return 0;
}
