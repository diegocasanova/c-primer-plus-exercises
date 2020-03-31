// Chapter 6 - Exercise 14
#include <stdio.h>

#define SIZE 8

void print_array(const int *);

int main(void) {
  int arr[SIZE], sum[SIZE];

  for (int i = 0; i < SIZE; i++) {
    printf("arr[%d]=", i);
    scanf("%d", &arr[i]);
  }

  sum[0] = arr[0];
  for (int i = 1; i < SIZE; i++) {
    sum[i] = arr[i] + sum[i - 1];
  }

  print_array(arr);
  print_array(sum);

  return 0;
}

void print_array(const int *array) {
  printf("[");
  for (int i = 0; i < SIZE; i++) {
    printf(" %d ", array[i]);
  }
  printf("]\n");
}
