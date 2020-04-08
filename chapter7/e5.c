// Chapter 7 - Exercise 5
#include <stdio.h>

#define BREAK '#'

int main(void) {
  char ch;
  unsigned int n_substitutions = 0;

  while ((ch = getchar()) != BREAK) {
    switch (ch) {
    case '!':
      printf("!!");
      n_substitutions++;
      break;
    case '.':
      putchar('!');
      n_substitutions++;
      break;
    default:
      putchar(ch);
    }
  }

  printf("\nSubstitutions: %d\n", n_substitutions);

  return 0;
}