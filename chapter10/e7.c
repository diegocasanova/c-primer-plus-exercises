// Chapter 10 - Exercise 7
#include "arrays.h"
#include <stdio.h>

#define SIZE_X 5
#define SIZE_Y 5

void copy_arr(int target[], const int source[], int size);
void copy_2d_arr(int target[][SIZE_X], const int source[][SIZE_X], int size);

int main(void) {

  int source[SIZE_Y][SIZE_X];
  int target[SIZE_Y][SIZE_X];

  load_2d_int_array(SIZE_X, SIZE_Y, source);
  printf("SOURCE:\n");
  print_2d_int_array(SIZE_X, SIZE_Y, source);
  copy_2d_arr(target, source, SIZE_Y);
  printf("TARGET:\n");
  print_2d_int_array(SIZE_X, SIZE_Y, target);

  return 0;
}

void copy_2d_arr(int target[][SIZE_X], const int source[][SIZE_X], int size) {
  for (int row = 0; row < size; row++) {
    copy_arr(target[row], source[row], SIZE_X);
  }
}

void copy_arr(int target[], const int source[], int size) {
  for (int i = 0; i < size; i++) {
    target[i] = source[i];
  }
}