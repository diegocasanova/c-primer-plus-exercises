// Chapter 12 - exercise 4
/* Write and test in a loop a function that returns the number of times it has
 * been called.
 */

#include <stdio.h>

static int counter = 0;

void count();

int main(void) {

  for (int i = 0; i < 20; i++) {
    count();
  }

  return 0;
}

void count() {
  counter++;
  printf("count: %d\n", counter);
}