// Chapter 6 - Exercise 2
#include <stdio.h>

#define ROWS 5
#define SIGN '$'

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
    printf("%c", SIGN);
  }
  printf("\n");
}
