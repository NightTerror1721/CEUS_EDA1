//
// Created by rcarlini on 25/11/19.
//

#ifndef EDA1_SEMINARS_SEMINAR_FILES_EXERCISES_H
#define EDA1_SEMINARS_SEMINAR_FILES_EXERCISES_H

#define MAX_LINE_LENGTH 100

void merge(FILE* fa, FILE* fb, FILE* fc);
int count_primes(FILE* fa);
int write_bars(FILE *fa, FILE *fout);
int print_mean_best_simple(FILE* f);
int print_mean_best_student(FILE* f);
int print_mean_best_course(FILE* f);
int print_mean_courses(FILE* f);

typedef struct {
	char  name[50];
	int   nia;
	float grade;
} Student;

typedef struct {
	int id;
	Student students[10];
	int count;
} Course;

float average_grade(const Course* course);

#endif //EDA1_SEMINARS_SEMINAR_FILES_EXERCISES_H
