#ifndef SEM_3_EXERCISES_H
#define SEM_3_EXERCISES_H

#define MAX_STRING_LEN 64

typedef struct {
	char name[MAX_STRING_LEN];
	int nia;
	float grade;

	int* costs;
	unsigned int cost_count;
} Student;

/* Exercise 2 */
void init_student(Student* s, char name[MAX_STRING_LEN], int nia, float grade);
void print_student(Student* s);
void read_student(Student* s);

void ex2a(void);
void ex2b(void);


/* Exercise 3 */
int read_bookcost(void);
int read_and_insert_bookcost(Student* s, unsigned int index);

void ex3(void);



#endif //SEM_3_EXERCISES_H