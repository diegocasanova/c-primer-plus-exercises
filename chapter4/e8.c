// Chapter 4 - exercise 8 - basic IO
#include <stdio.h>

#define LITERS_PER_GALLON 3.785
#define KMS_PER_MILE 1.609

int main(void) {

  float miles, gasoline;

  printf("Miles traveled: ");
  scanf("%f", &miles);

  printf("Gasoline (gallons): ");
  scanf("%f", &gasoline);

  float liters = gasoline * LITERS_PER_GALLON;
  float kms = miles * KMS_PER_MILE;

  printf("%.1f miles per gallon\n", miles / gasoline);
  printf("%.1f liters per 100 km\n", (liters / kms) * 100);

  return 0;
}