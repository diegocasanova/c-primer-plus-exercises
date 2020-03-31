// Chapter 6 - Exercise 5
#include <stdio.h>

void print_spaces(int);
void print_ascending(int);
void print_descending(int);

int main(void) {
  char chr;
  int rows;

  do {
    printf("Enter an uppercase letter: ");
  } while (scanf("%c", &chr) == 0);

  rows = chr - 'A';

  for (int i = 0; i <= rows; i++) { // rows
    print_spaces(rows - i);
    print_ascending(i);
    print_descending(i);
    printf("\n");
  }
  printf("\n");

  return 0;
}

void print_spaces(int limit) {
  for (int j = 0; j < limit; j++) {
    printf(" ");
  }
}

void print_ascending(int limit) {
  char chr = 'A';
  for (int j = 0; j < limit; j++) {
    printf("%c", chr + j);
  }
}

void print_descending(int limit) {
  char chr = 'A' + limit;
  for (int j = 0; j <= limit; j++) {
    printf("%c", chr - j);
  }
}
