// Chapter 10 - Exercises 3 - 6
#include "arrays.h"
#include <stdio.h>

#define SOURCE_SIZE 5

int max(const int *arr, int size);
int max_index(const int *arr, int size);
int difference_max_min(const int *arr, int size);
void reverse(int *arr, int size);
void swap(int *a, int *b);

int main(void) {

  int source[SOURCE_SIZE];

  load_int_array(source, SOURCE_SIZE);
  print_int_array(source, SOURCE_SIZE);
  printf("max element: %d\n", max(source, SOURCE_SIZE));
  printf("max index: %d\n", max_index(source, SOURCE_SIZE));
  printf("difference max - min: %d\n", difference_max_min(source, SOURCE_SIZE));
  reverse(source, SOURCE_SIZE);
  print_int_array(source, SOURCE_SIZE);

  return 0;
}

int max(const int *arr, int size) {
  int max = *arr;
  for (int i = 0; i < size; i++) {
    if (*(arr + i) > max) {
      max = *(arr + i);
    }
  }
  return max;
}

int max_index(const int *arr, int size) {
  int max = 0;
  for (int i = 0; i < size; i++) {
    if (*(arr + i) > *(arr + max)) {
      max = i;
    }
  }
  return max;
}

int difference_max_min(const int *arr, int size) {
  int max = *arr;
  int min = *arr;
  for (int i = 0; i < size; i++) {
    if (*(arr + i) > max) {
      max = *(arr + i);
    } else if (*(arr + i) < min) {
      min = *(arr + i);
    }
  }
  return max - min;
}

void reverse(int *arr, int size) {
  for (int i = 0, j = size - 1; i < j; i++, j--) {
    swap(arr + i, arr + j);
  }
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}