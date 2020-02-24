#include <stdio.h>
#include <math.h>
#include "seminar-recursion-exercises.h"

// Exercise 11
int vector_sum_subs_rec(int* v1, int* v2, int idx, int size) {
    if (idx >= size)
        return 0;

    int result;
    if(((idx + 1) % 2) == 0)
        result = v1[idx] + v2[idx];
    else result = -(v1[idx] + v2[idx]);

    return vector_sum_subs_rec(v1, v2, idx + 1, size) + result;
}

int vector_sum_subs_iter(int* v1, int* v2, int size) {
    int result = 0;
    for (int i = 0; i < size; ++i)
    {
        if(((i + 1) % 2) == 0)
            result += v1[i] + v2[i];
        else result -= v1[i] + v2[i];
    }
    return result;
}

int vector_sum_subs(int* v1, int* v2, int size) {
    return vector_sum_subs_rec(v1, v2, 0, size);
}

// Exercise 12
int sum_digits(int number) {
    if (number < 10)
        return number;

    int result = number % 10;
    return sum_digits(number / 10) + result;
}

// Exercise 13
int reverse_digits_simple(int number, int acum) {
    if (number < 10)
        return acum * 10 + number;

    acum = acum * 10 + (number % 10);
    return reverse_digits_simple(number / 10, acum);
}

int reverse_digits_hard(int number) {
    if (number < 10)
        return number;

    int result = number % 10;
    int unit = 10;
    number /= 10;
    while (unit < number)
        unit *= 10;

    return result * unit + reverse_digits_hard(number);
}

int reverse_digits(int number) {
    return reverse_digits_hard(number);
    //return reverse_digits_simple(number, 0);
}

// Exercise 14
int norm_rec_rec(int* vector, int size, int acum) {
    if (size < 1)
        return (int) sqrt(acum);

    size -= 1;
    acum += (int) pow(vector[size], 2);

    return norm_rec_rec(vector, size, acum);
}

int norm(int* vector, int size) {
    return norm_rec_rec(vector, size, 0);
}

// Exercise 15
int mystery (int n, int result) {
    if (n<=0) {
        return result;
    } else {
        return mystery(n-1, result + n*n);
    }
}

// Exercise 16
int is_perfect_square_rec(int number, int step) {
    int sq = step * step;
    if (sq > number)
        return 0;
    if (sq == number)
        return step;
    return is_perfect_square_rec(number, step + 1);
}

int is_perfect_square(int number) {
    return is_perfect_square_rec(number, 1);
}

// Exercise 17
int free_of_squares_rec(int number, int step) {
    if (step > number / 2)
        return FALSE;

    float div = number / (float)step;
    if ((float)((int)div) == div) // Probamos si div es divisor de number
        if(is_perfect_square((int)div))
            return TRUE;

    return free_of_squares_rec(number, step + 1);
}

int free_of_squares(int number) {
    return free_of_squares_rec(number, 1);
}

// Exercise 18
int reverse_and_sum_rec(int number, int depth) {
    if (depth >= MAX_DEPTH)
        return MAX_DEPTH_REACHED;

    int inverse = reverse_digits(number);
    if (number == inverse)
        return number;

    return reverse_and_sum_rec(number + inverse, depth + 1);
}

int reverse_and_sum(int number) {
    return reverse_and_sum_rec(number, 0);
}

// Exercise 19
int binary_search_rec(int* vector, int left, int right, int number) {
    if (left <= right)
    {
        int mid = (left + right) / 2;
        if (vector[mid] == number)
            return TRUE;
        else if (vector[mid] < number)
            return binary_search_rec(vector, mid + 1, right, number);
        else return binary_search_rec(vector, left, mid - 1, number);
    }

    return FALSE;
}

int binary_search(int* vector, int size, int number) {
    return binary_search_rec(vector, 0, size - 1, number);
}
