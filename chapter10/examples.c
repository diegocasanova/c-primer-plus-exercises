// Chapter 10 - Examples

#include <stdio.h>

#define SIZE 10

void print_array(const int *, const int *);
void print_array_n(const int[], int);
void add_to_array(int *, int, int);

int main() {

  int arr[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  print_array(arr, arr + SIZE);
  add_to_array(arr, SIZE, 2);
  print_array_n(arr, SIZE);

  return 0;
}

void print_array(const int *start, const int *end) {
  printf("[");
  while (start < end) {
    printf(" %d ", *(start++));
  }
  printf("]\n");
}

void print_array_n(const int arr[], int n) {
  printf("[");
  for (int i = 0; i < SIZE; i++) {
    printf(" %d ", arr[i]);
  }
  printf("]\n");
}

void add_to_array(int *arr, int size, int number) {
  for (int i = 0; i < size; i++) {
    arr[i] += number;
  }
}