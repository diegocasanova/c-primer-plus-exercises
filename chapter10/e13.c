// Chapter 10 - Exercise 13
/*
Write a program that prompts the user to enter three sets of five double numbers
each. (You may assume the user responds correctly and doesn’t enter non-numeric
data.) The program should accomplish all of the following:
a. Store the information in a 3×5 array.
b. Compute the average of each set of five values.
c. Compute the average of all the values.
d. Determine the max_val value of the 15 values.
e. Report the results.
All the process will be accomplish on the main function to avoid the array
scanning multiple times
*/
#include "arrays.h"
#include <stdio.h>

#define SIZE_X 5
#define SIZE_Y 3

int main(void) {

  int source[SIZE_Y][SIZE_X];
  int row_acc, acc, max_val;
  row_acc = acc = max_val = 0;

  load_2d_int_array(SIZE_X, SIZE_Y, source);
  printf("SOURCE:\n");
  print_2d_int_array(SIZE_X, SIZE_Y, source);

  max_val = source[0][0];

  for (int j = 0; j < SIZE_Y; j++) {
    row_acc = 0;
    for (int i = 0; i < SIZE_X; i++) {
      row_acc += source[j][i];
      acc += source[j][i];
      if (max_val < source[j][i]) {
        max_val = source[j][i];
      }
    }
    printf("avg row[%d] = [%.2f]\n", j, ((double)row_acc / (double)SIZE_X));
  }
  printf("avg = %.2f\n", ((double)row_acc / (double)(SIZE_X * SIZE_Y)));
  printf("max value = %d\n", max_val);

  return 0;
}
