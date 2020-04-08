// Chapter 4 - exercise 4 - basic IO
#include <stdio.h>

int main(void) {

  float height; // in centimeters
  char name[40];

  printf("Height (cms): ");
  scanf("%f", &height);
  printf("Name: ");
  scanf("%s", name);

  printf("%s, you are %1.2f meters tall\n", name, height / 100);

  return 0;
}