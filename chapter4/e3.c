// Chapter 4 - exercise 3 - basic IO
#include <stdio.h>

int main(void) {

  float number;

  printf("Number: ");
  scanf("%f", &number);

  printf("%2.1f\n", number);
  printf("%2.1e\n", number);

  printf("%+2.3f\n", number);
  printf("%2.3E\n", number);

  return 0;
}