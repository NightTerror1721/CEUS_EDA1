#include <stdio.h>
#include <string.h>

#include "common.h"
#include "seminar-files-exercises.h"

// Exercise 1
void merge(FILE* fa, FILE* fb, FILE* fc) {
    int readed, value;

    while ((readed = fscanf(fa, "%d\n", &value)) > 0)
        fprintf(fc, "%d\n", value);

    while ((readed = fscanf(fb, "%d\n", &value)) > 0)
        fprintf(fc, "%d\n", value);
}

// Exercise 2

int is_prime(int n) {
    if (n == 1 || n == -1)
        return TRUE;

    for (int i = 2; i <= n / 2; ++i)
        if (n % i == 0)
            return FALSE;

    return TRUE;
}

int count_primes(FILE* fa) {
    
    int readed, value, count = 0;
    while ((readed = fscanf(fa, "%d ", &value)) > 0)
        if (is_prime(value))
            ++count;
    return count;
}

// Exercise 3

void print_bar(int size, FILE *f){
    while (size--)
        fprintf(f, "*");
    fprintf(f, "\n");
}

int write_bars(FILE *fa, FILE *fout) {
    
    int readed, value;
    while ((readed = fscanf(fa, "%d ", &value)) > 0)
    {
        print_bar(value, fout);
        print_bar(value, stdout);
    }

    return SUCCESS;
}

// Exercise 4a

#define EXPECTED_MATCHES_EX_15 3

int print_mean_best_simple(FILE* f) {
    return ERROR;
}

// Exercise 4b

int print_mean_best_student(FILE* f) {
    return ERROR;
}

// Exercise 4c

int print_mean_best_course(FILE* f) {
    return ERROR;
}

// Exercise 5

#define MAX_COURSES 10
#define EXPECTED_MATCHES_EX_16 4

int print_mean_courses(FILE* f) {
    return ERROR;
}

// Exercise 6

int cat() {
    return ERROR;
}
