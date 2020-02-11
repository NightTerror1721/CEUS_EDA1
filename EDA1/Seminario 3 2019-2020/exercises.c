#include "exercises.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void init_student(Student* s, char name[MAX_STRING_LEN], int nia, float grade)
{
	strcpy(s->name, name);
	s->nia = nia;
	s->grade = grade;
}

void print_student(Student* s)
{
	printf("[name: %s; nia: %d; grade: %f]", s->name, s->nia, s->grade);
}

void read_student(Student* s)
{
	printf("Student name:\n");
	scanf_s("%s\n", s->name, MAX_STRING_LEN);

	printf("Student nia:\n");
	scanf("%d\n", &s->nia);

	printf("Student grade:\n");
	scanf("%f\n", &s->grade);
}

void ex2a()
{
	Student* s = (Student*)malloc(sizeof(Student));
	read_student(s);
	print_student(s);
	free(s);
}

void ex2b()
{
	unsigned int count;
	printf("Number of students:\n");
	scanf("%u\n", &count);

	if (count == 0)
		return;

	Student* s = (Student*)malloc(sizeof(Student) * count);
	if (s != NULL)
	{
		for (unsigned int i = 0; i < count; ++i)
		{
			printf("Student number %u", i);
			read_student(&s[i]);
		}
		for (unsigned int i = 0; i < count; ++i)
			print_student(&s[i]);
		free(s);
	}
}
