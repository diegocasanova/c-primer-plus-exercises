// Chapter 6 - Exercise 7
#include <stdio.h>
#include <string.h>

void print_inverted(const char *word);

int main(void) {
  char word[40];

  do {
    printf("Enter a word: ");
  } while (scanf("%s", word) == 0);

  print_inverted(word);
  printf("\n");

  return 0;
}

void print_inverted(const char *word) {
  for (int i = strlen(word) - 1; i >= 0; i--) {
    printf("%2c", word[i]);
  }
}
