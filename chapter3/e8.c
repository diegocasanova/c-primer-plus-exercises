// Chapter 3 - exercise 8 - cups to pints/ounces/tablespoons/teaspoons

#include <stdio.h>

#define CUPS_PER_PINT 2
#define OUNCES_PER_CUP 8
#define TABLESPOONS_PER_OUNCE 2
#define TEASPOONS_PER_TABLESPOONS 3

int main(void) {

  float cups;

  printf("volume in cups: ");
  scanf("%f", &cups);

  float ounces = cups * OUNCES_PER_CUP;
  float tablespoons = ounces * TABLESPOONS_PER_OUNCE;
  printf("volume in pints: %.2f\n", cups / CUPS_PER_PINT);
  printf("volume in ounces: %.2f\n", ounces);
  printf("volume in tablespoons: %.2f\n", tablespoons);
  printf("volume in teaspoons: %.2f\n",
         tablespoons * TEASPOONS_PER_TABLESPOONS);

  return 0;
}