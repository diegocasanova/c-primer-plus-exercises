// Chapter 7 - Exercise 3
#include <stdio.h>

int main(void) {

  int n_odd, n_even, sum_odd, sum_even, read;
  n_odd = n_even = sum_even = sum_odd = 0;

  while ((scanf("%d", &read) == 1) && read != 0) {
    if (read % 2 == 0) {
      n_even++;
      sum_even += read;
    } else {
      n_odd++;
      sum_odd += read;
    }
  }

  printf("ODD - total numbers: %d | average: %.2d \n", n_odd, sum_odd / n_odd);
  printf("EVEN - total numbers: %d | average: %.2d \n", n_even,
         sum_even / n_even);

  return 0;
}