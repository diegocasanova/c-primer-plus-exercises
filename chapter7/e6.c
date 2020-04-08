// Chapter 7 - Exercise 6
#include <stdio.h>

#define BREAK '#'

int main(void) {
  char ch, previous_ch = ' ';
  unsigned int n_ie = 0;

  ch = getchar();
  while (ch != BREAK) {
    if (previous_ch == 'e' && ch == 'i') {
      n_ie++;
    }
    previous_ch = ch;
    ch = getchar();
  }

  printf("\n'ie' ocurrences: %d\n", n_ie);

  return 0;
}