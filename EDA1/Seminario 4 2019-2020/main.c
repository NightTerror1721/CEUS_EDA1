#include <stdio.h>
#include "seminar-recursion-exercises.h"

#define MAX_NUMBERS 5

void ex11() {
    printf("\nExercise 11\n");

    int v1[MAX_NUMBERS] = {5, 2, 6, 4, 5};
    int v2[MAX_NUMBERS] = {0, 2, 5, 4, 1};

    int total = vector_sum_subs(v1, v2, MAX_NUMBERS);
    printf("The total for ex11 is %d\n", total);

    int v3[MAX_NUMBERS] = {5, 2, 5, 4, 1};

    total = vector_sum_subs(v1, v3, MAX_NUMBERS);
    printf("The total for ex11 is %d\n", total);
}

void ex12() {
    printf("\nExercise 12\n");

    int number = 143;
    int total = sum_digits(number);
    printf("The sum of the digits for %d is %d\n", number, total);

    number = 33113;
    total = sum_digits(number);
    printf("The sum of the digits for %d is %d\n", number, total);
}

void ex13() {
    printf("\nExercise 13\n");

    int number = 143;
    int inverted = reverse_digits(number);
    printf("The reverse of the number %d is %d\n", number, inverted);

    number = 1432;
    inverted = reverse_digits(number);
    printf("The reverse of the number %d is %d\n", number, inverted);
}

void ex14() {
    printf("\nExercise 14\n");

    int vector[MAX_NUMBERS] = {1, 2, 3, 1, 1};
    int total = norm(vector, MAX_NUMBERS);
    printf("The norm of the vector is %d\n", total);
}

void ex15() {
    printf("\nExercise 15\n");

    int result = mystery (5, 0);
    printf("The result of calling mistery is %d\n", result);
}

void ex16() {
    printf("\nExercise 16\n");

    int number = 143;
    int result = is_perfect_square(number);
    printf("The result of checking if %d is a perfect square is %d\n", number, result);

    number = 144;
    result = is_perfect_square(number);
    printf("The result of checking if %d is a perfect square is %d\n", number, result);
};

void ex17() {
    printf("\nExercise 17\n");

    int number = 143;
    int result = free_of_squares(number);
    if (result == TRUE) {
        printf("The number %d is free of squares\n", number);
    } else {
        printf("The number %d is NOT free of squares\n", number);
    }

    number = 20;
    result = free_of_squares(number);
    if (result == TRUE) {
        printf("The number %d is free of squares\n", number);
    } else {
        printf("The number %d is NOT free of squares\n", number);
    }
}

void ex18() {
    printf("\nExercise 18\n");

    int number = 59;
    int result = reverse_and_sum(number);
    if (result == MAX_DEPTH_REACHED) {
        printf("The number %d didn't produce a palindrome (stopped at depth %d).\n", number,  MAX_DEPTH);
    } else {
        printf("The number %d produced the palindrome %d\n", number, result);
    }

    number = 196;
    result = reverse_and_sum(number);
    if (result == MAX_DEPTH_REACHED) {
        printf("The number %d didn't produce a palindrome (stopped at depth %d).\n", number, MAX_DEPTH);
    } else {
        printf("The number %d produced the palindrome %d\n", number, result);
    }
}

void ex19() {
    printf("\nExercise 19\n");

    int number = 2;
    int v1[] = {2, 3, 4, 5, 6};

    int result = binary_search(v1, 5, number);
    if (result == TRUE) {
        printf("The number %d was found in the vector!\n", number);
    } else {
        printf("The number %d was NOT found in the vector!\n", number);
    }

    int v2[] = {1, 3, 5, 7, 9};

    result = binary_search(v2, 5, number);
    if (result == TRUE) {
        printf("The number %d was found in the vector!\n", number);
    } else {
        printf("The number %d was NOT found in the vector!\n", number);
    }


    int v3[] = {1, 1, 1, 1, 1, 2};

    result = binary_search(v3, 6, number);
    if (result == TRUE) {
        printf("The number %d was found in the vector!\n", number);
    } else {
        printf("The number %d was NOT found in the vector!\n", number);
    }
}

int main() {

    ex11();
    ex12();
    ex13();
    ex14();
    ex15();
    ex16();
    ex17();
    ex18();
    ex19();
}