// Chapter 10 - Exercise 8
#include "arrays.h"
#include <stdio.h>

#define SIZE 7
#define SIZE_TARGET 3

void copy_arr(int target[], const int source[], int size);

int main(void) {

  int source[SIZE];
  int target[SIZE_TARGET];

  load_int_array(source, SIZE);
  copy_arr(target, &target[2], SIZE_TARGET);
  printf("SOURCE: ");
  print_int_array(source, SIZE);
  printf("TARGET: ");
  print_int_array(target, SIZE_TARGET);

  return 0;
}

void copy_arr(int target[], const int source[], int size) {
  for (int i = 0; i < size; i++) {
    target[i] = source[i];
  }
}