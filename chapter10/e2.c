// Chapter 10 - Exercise 2
#include <stdio.h>

#define SOURCE_SIZE 5

void print_array(double *start, double *end);
void copy_arr(double target[], const double source[], double size);
void copy_ptr(double *target, const double *source, int size);
void copy_ptrs(double *target, const double *src_start, const double *src_end);

int main(void) {

  double source[SOURCE_SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5};
  double target1[SOURCE_SIZE];
  double target2[SOURCE_SIZE];
  double target3[SOURCE_SIZE];

  copy_arr(target1, source, SOURCE_SIZE);
  copy_ptr(target2, source, SOURCE_SIZE);
  copy_ptrs(target3, source, source + SOURCE_SIZE);
  printf("TARGET1 ->");
  print_array(target1, target1 + SOURCE_SIZE);
  printf("TARGET2 ->");
  print_array(target2, target2 + SOURCE_SIZE);
  printf("TARGET3 ->");
  print_array(target3, target3 + SOURCE_SIZE);

  return 0;
}

void copy_arr(double target[], const double source[], double size) {
  for (int i = 0; i < size; i++) {
    target[i] = source[i];
  }
}

void copy_ptr(double *target, const double *source, int size) {
  for (int i = 0; i < size; i++) {
    *(target + i) = *(source + i);
  }
}

void copy_ptrs(double *target, const double *src_start, const double *src_end) {
  while (src_start < src_end) {
    *(target++) = *(src_start++);
  }
}

void print_array(double *start, double *end) {
  printf("[");
  while (start < end) {
    printf(" %.2f ", *(start++));
  }
  printf("]\n");
}
