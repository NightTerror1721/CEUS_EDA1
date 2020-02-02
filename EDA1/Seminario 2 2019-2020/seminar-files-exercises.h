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

int cat();

#endif //EDA1_SEMINARS_SEMINAR_FILES_EXERCISES_H
