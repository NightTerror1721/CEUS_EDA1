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

    char name[50], best_name[50];
    float grade, best_grade = -1;
    int readed, nia, best_nia = -1;

    while ((readed = fscanf(f, "%s %d %f\n", name, &nia, &grade)) > 0)
    {
        if ((best_nia < 0 && best_grade < 0) || (best_grade < grade))
        {
            strcpy(best_name, name);
            best_nia = nia;
            best_grade = grade;
        }
    }
    if (best_nia < 0 && best_grade < 0)
        return ERROR;

    printf("%s with nia %d: %f\n", best_name, best_nia, best_grade);

    return SUCCESS;
}

// Exercise 4b

int print_mean_best_student(FILE* f) {

    Student students[10];
    Student best;
    int readed, count = 0;

    while ((readed = fscanf(f, "%s %d %f\n", students[count].name, &students[count].nia, &students[count].grade)) > 0)
        ++count;

    for (int i = 0; i < count; ++i)
        if (i < 1 || best.grade < students[i].grade)
            best = students[i];

    printf("%s with nia %d: %f\n", best.name, best.nia, best.grade);

    return SUCCESS;
}

// Exercise 4c

int print_mean_best_course(FILE* f) {

    Course course = { .id = 0, .count = 0 };
    Student best;
    int readed;

    while ((readed = fscanf(
        f,
        "%s %d %f\n",
        course.students[course.count].name,
        &course.students[course.count].nia,
        &course.students[course.count].grade
    )) > 0){
        ++course.count;
    }

    for (int i = 0; i < course.count; ++i)
        if (i < 1 || best.grade < course.students[i].grade)
            best = course.students[i];

    printf("%s with nia %d: %f\n", best.name, best.nia, best.grade);

    return SUCCESS;
}

float average_grade(const Course* course)
{
    float avg = 0;

    for (int i = 0; i < course->count; ++i)
        avg += course->students[i].grade;
    avg /= course->count;

    return avg;
}

// Exercise 5

#define MAX_COURSES 10
#define EXPECTED_MATCHES_EX_16 4

int print_mean_courses(FILE* f) {
    
    Course courses[10];
    Student s;
    int readed, course_code, course_count = 0;

    while ((readed = fscanf(f, "%s %d %f %d\n", s.name, &s.nia, &s.grade, &course_code)) > 0)
    {
        int course_index = -1;
        for(int i = 0; i < course_count; ++i)
            if (courses[i].id == course_code)
            {
                course_index = i;
                break;
            }

        if (course_index < 0)
        {
            courses[course_count].id = course_code;
            courses[course_count].count = 0;
            course_index = course_count++;
        }

        courses[course_index].students[courses[course_index].count++] = s;
    }

    for (int i = 0; i < course_count; ++i)
    {
        float avg = average_grade(&courses[i]);
        printf("Average of %d course: %f\n", courses[i].id, avg);
    }

    return SUCCESS;
}

// Exercise 6

int cat() {
    return ERROR;
}
