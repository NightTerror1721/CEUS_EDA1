#ifndef SEM_3_EXERCISES_H
#define SEM_3_EXERCISES_H

#define MAX_STRING_LEN 64

typedef struct {
	char name[MAX_STRING_LEN];
	int nia;
	float grade;
} Student;

void init_student(Student* s, char name[MAX_STRING_LEN], int nia, float grade);

void print_student(Student* s);

void read_student(Student* s);

void ex2a();

void ex2b();


#endif //SEM_3_EXERCISES_H