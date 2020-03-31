// Chapter 7 - Exercise 2
#include <stdio.h>

#define QUIT '#'

int main(void) {

  char ch;
  unsigned int n_chars = 0;

  while ((ch = getchar()) != QUIT) {
    n_chars++;
    printf("|%2c - %3d |\t", ch, ch);
    if (n_chars % 8 == 0) {
      printf("\n");
    }
  }
  printf("\n");

  return 0;
}