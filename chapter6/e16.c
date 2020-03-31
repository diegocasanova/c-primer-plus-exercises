// Chapter 6 - Exercise 16
#include <stdio.h>

#define DAPHNE_INT 0.10
#define DEIRDRE_INT 0.05
#define INVESTMENT 100

int main(void) {

  float sum_deirdre, sum_daphne;
  sum_daphne = sum_deirdre = INVESTMENT;
  int years = 0;

  for (years = 0; sum_daphne >= sum_deirdre; years++) {
    sum_deirdre += sum_deirdre * DEIRDRE_INT;
    sum_daphne += INVESTMENT * DAPHNE_INT;
  }

  printf("years: %d\n", years);
  printf("Daphne sum: %.2f\n", sum_daphne);
  printf("Deirdre sum: %.2f\n", sum_deirdre);

  return 0;
}
