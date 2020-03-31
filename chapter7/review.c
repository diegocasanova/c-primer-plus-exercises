// Chapter 7 - Review questions
#include <stdio.h>

#define QUIT '#'

void question_9();

int main(void) {
  question_9();

  return 0;
}

void question_9(void) {

  char ch;

  while ((ch = getchar()) != QUIT) {
    if (ch != '\n') {
      printf("Step 1\n");

      if (ch != 'c') {

        if (ch == 'b')
          break;

        if (ch != 'h')
          printf("Step 2\n");

        printf("Step 3\n");
      }
    }
  }

  printf("Done\n");
}