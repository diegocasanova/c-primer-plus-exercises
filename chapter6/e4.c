// Chapter 6 - Exercise 4
#include <stdio.h>

#define ROWS 6

int main(void) {
  char chr = 'A';
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j <= i; j++, chr++) {
      printf("%c", chr);
    }
    printf("\n");
  }
  printf("\n");
  return 0;
}
