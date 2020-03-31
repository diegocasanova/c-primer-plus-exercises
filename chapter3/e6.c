// Chapter 3 - exercise 6 - water molecules in quart of water

#include <stdio.h>

#define WATER_MOL_MASS 3.0E-23
#define GRAMS_PER_QUART 950

int main(void) {

  float water_quarts;

  printf("water quarts: ");
  scanf("%f", &water_quarts);

  printf("water molecules: %e\n",
         (water_quarts * GRAMS_PER_QUART) / WATER_MOL_MASS);

  return 0;
}