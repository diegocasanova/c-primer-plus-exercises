#include "arrays.h"
#include <stdio.h>

void print_int_array(const int *arr_start, int size) {
  printf("[");
  for (int i = 0; i < size; i++) {
    printf(" %d ", arr_start[i]);
  }
  printf("]\n");
}

void print_2d_int_array(int size_x, int size_y, const int arr[size_y][size_x]) {
  for (int j = 0; j < size_y; j++) {
    print_int_array(arr[j], size_x);
  }
}

void load_int_array(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("[%d]=", i);
    scanf("%d", &arr[i]);
  }
}

void load_2d_int_array(int size_x, int size_y, int arr[size_y][size_x]) {
  for (int j = 0; j < size_y; j++) {
    printf("row [%d]\n", j);
    load_int_array(arr[j], size_x);
  }
}