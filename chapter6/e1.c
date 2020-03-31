// Chapter 6 - Exercise 1
#include <stdio.h>

#define ALFABET_LETTERS 26

int main(void) {

  char letters[ALFABET_LETTERS];

  for (int i = 0; i < ALFABET_LETTERS; i++) {
    letters[i] = 'a' + i;
  }

  for (int i = 0; i < ALFABET_LETTERS; i++) {
    printf("%4c", letters[i]);
  }
  printf("\n");

  return 0;
}
