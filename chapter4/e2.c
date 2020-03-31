// Chapter 4 - exercise 2 - basic IO
#include <stdio.h>
#include <string.h>

int main(void) {

  char name[30];
  int len;

  printf("Name: ");
  scanf("%s", name);
  len = strlen(name);

  printf("\"%s\"\n", name);
  printf("\"%20s\"\n", name);
  printf("\"%-20s\"\n", name);
  printf("\"%*s\"\n", len + 3, name);

  return 0;
}