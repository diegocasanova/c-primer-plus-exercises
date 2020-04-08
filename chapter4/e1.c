// Chapter 4 - exercise 1 - basic IO
#include <stdio.h>

int main(void) {

  char name[30], surname[40];

  printf("Name & Surname: ");
  scanf("%s %s", name, surname);
  printf("%s, %s\n", surname, name);

  return 0;
}