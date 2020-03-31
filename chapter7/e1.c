// Chapter 7 - Exercise 1
#include <stdio.h>

#define QUIT '#'

int main(void) {

  char ch;
  unsigned int n_spaces, n_newline, n_chars;
  n_spaces = n_newline = n_chars = 0;

  while ((ch = getchar()) != QUIT) {
    if (ch == ' ') {
      n_spaces++;
      continue;
    }

    if (ch == '\n') {
      n_newline++;
      continue;
    }
    n_chars++;
  }

  printf("%15s%15s%15s\n", "spaces", "newlines", "characters");
  printf("%15d%15d%15d\n", n_spaces, n_newline, n_chars);

  return 0;
}