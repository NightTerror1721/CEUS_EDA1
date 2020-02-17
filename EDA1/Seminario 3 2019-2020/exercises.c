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
	fgets(s->name, MAX_STRING_LEN, stdin);

	printf("Student nia:\n");
	scanf("\n%d", &s->nia);

	printf("Student grade:\n");
	scanf("\n%f", &s->grade);
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
	scanf("\n%u", &count);

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




/* Exercise 3 */

int read_bookcost()
{
	int cost;
	printf("Enter the book cost:\n");
	if (scanf("\n%d", &cost) < 1)
		return -1;
	return cost;
}

int read_and_insert_bookcost(Student* s, unsigned int index)
{
	int cost = 0;
	do
	{
		cost = read_bookcost();
		if (cost < 1)
			printf("Invalid cost\n");
		else
			s->costs[index] = cost;

	} while (cost <= 0);
	return cost;
}

void ex3()
{
	Student s;
	int total_cost = 0;
	read_student(&s);


	/* 3A */
	s.costs = (int*) malloc(sizeof(int) * 4);
	s.cost_count = 4;

	for (int i = 0; i < 4; ++i)
	{
		int cost = read_and_insert_bookcost(&s, i);
		total_cost += cost;
	}
	printf("The total cost for student %s is %d\n", s.name, total_cost);


	/* 3B */
	s.costs = realloc(s.costs, sizeof(int) * 6);
	s.cost_count = 6;

	for (int i = 4; i < 6; ++i)
	{
		int cost = read_and_insert_bookcost(&s, i);
		total_cost += cost;
	}
	printf("The new total cost for student %s is %d\n", s.name, total_cost);
}
