// Chapter 3 - exercise 7 - centimeters to inches

#include <stdio.h>

#define INCH_PER_CENT 0.3937008

int main(void) {

  float height; // in centimeters

  printf("height in centimeters: ");
  scanf("%f", &height);

  printf("height in inches: %.2f\n", height * INCH_PER_CENT);

  return 0;
}