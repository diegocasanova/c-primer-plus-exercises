// Chapter 6 - Exercise 3
#include <stdio.h>

#define ROWS 6

void print_row(int);

int main(void) {

  for (int i = 1; i <= ROWS; i++) {
    print_row(i);
  }
  printf("\n");

  return 0;
}

void print_row(int limit) {
  for (int i = 0; i < limit; i++) {
    printf("%c", 'F' - i);
  }
  printf("\n");
}
