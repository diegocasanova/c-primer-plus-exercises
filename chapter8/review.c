// Chapter 8 -review exercises

#include <stdio.h>

int main(void) {

  int ch;
  unsigned int count = 0;

  while ((ch = getchar()) != EOF) {
    count++;
  }

  printf("Characters: %d\n", count);

  return 0;
}