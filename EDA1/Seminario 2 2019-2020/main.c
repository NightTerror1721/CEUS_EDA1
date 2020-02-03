#include <stdio.h>
#include "common.h"
#include "seminar-files-exercises.h"

int ex1() {

    printf("Executing exercise %d...\n", 1);

    int status = SUCCESS;

    FILE *fa, *fb, *fc;
    fa = fopen("resources/A.txt", "r");
    fb = fopen("resources/B.txt", "r");
    fc = fopen("resources/C.txt", "w");

    if (!fa || !fb || !fc)
        return ERROR;

    merge(fa, fb, fc);

    fclose(fa);
    fclose(fb);
    fclose(fc);

    return status;
}

int ex2() {

    printf("Executing exercise %d...\n", 2);

    int status = SUCCESS;

    FILE* f = fopen("resources/input.txt", "r");

    if (!f)
        return ERROR;

    int primes = count_primes(f);
    printf("Found %d primes\n", primes);

    fclose(f);

    return status;
}

int ex3() {

    printf("Executing exercise %d...\n", 3);

    int status = SUCCESS;

    FILE *fa, *fout;
    fa   = fopen("resources/input.txt", "r");
    fout = fopen("resources/diagrama.txt", "w");

    if (!fa || !fout)
        return ERROR;

    status = write_bars(fa, fout);

    fclose(fa);
    fclose(fout);

    return status;
}


int ex4a() {

    printf("Executing exercise %s...\n", "4a");

    int status = SUCCESS;

    FILE* f = fopen("resources/students.txt", "r");

    if (!f)
        return ERROR;

    status = print_mean_best_simple(f);

    fclose(f);

    return status;
}

int ex4b() {
    printf("Executing exercise %s...\n", "4b");

    int status = SUCCESS;

    FILE* f = fopen("resources/students.txt", "r");

    if (!f)
        return ERROR;

    status = print_mean_best_student(f);

    fclose(f);

    return status;
}

int ex4c() {

    printf("Executing exercise %s...\n", "4c");

    int status = SUCCESS;

    FILE* f = fopen("resources/students.txt", "r");

    if (!f)
        return ERROR;

    status = print_mean_best_course(f);

    fclose(f);

    return status;
}


int ex5() {
    printf("Executing exercise %s...\n", "5");

    int status = SUCCESS;

    FILE* f = fopen("resources/courses.txt", "r");

    if (!f)
        return ERROR;

    status = print_mean_courses(f);

    fclose(f);

    return status;
}

int main() {

    ex1();
    ex2();
    ex3();
    ex4a();
    ex4b();
    ex4c();
    ex5();

    return 0;
}