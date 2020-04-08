#include <stdio.h>

#define CENT_PER_INCH 2.54

int main(void) {
  float inches = 0;

  printf("Inches: ");
  scanf("%f", &inches);

  printf("Centimetres: %.2f\n", CENT_PER_INCH * inches);

  return 0;
}