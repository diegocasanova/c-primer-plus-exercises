// Chapter 6 - Examples
#include <stdio.h>

int get_number(int *number);

int main(void) {

  int num = 0;

  while (get_number(&num) == 1) {
    printf("int=%d  char=%c\n", num, num);
  }

  return 0;
}

int get_number(int *number) {
  printf("Please enter a number (letter to quit): ");
  return scanf("%d", number);
}