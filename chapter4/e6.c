// Chapter 4 - exercise 6 - basic IO
#include <stdio.h>
#include <string.h>

int main(void) {

  char name[40], surname[50];

  printf("name: ");
  scanf("%s", name);
  printf("surname: ");
  scanf("%s", surname);

  int len_name, len_surname;
  len_name = strlen(name);
  len_surname = strlen(surname);

  printf("%*s %*s\n", len_name, name, len_surname, surname);
  printf("%-*d %-*d\n", len_name, len_name, len_surname, len_surname);

  return 0;
}