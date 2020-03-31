// Chapter 6 - Exercise 12
#include <stdio.h>

void scan_limit(int *);
double serie(int limit);
double serie_alternate(int limit);

int main(void) {
  int limit;

  scan_limit(&limit);
  while (limit > 0) {
    printf("%10fl%10fl\n", serie(limit), serie_alternate(limit));
    scan_limit(&limit);
  }

  printf("\n");

  return 0;
}

double serie(int limit) {
  double acc = 0.0;
  for (int i = 0; i < limit; i++) {
    acc += 1.0 / (i + 1);
  }
  return acc;
}

double serie_alternate(int limit) {
  double acc = 0.0;
  int exp = 0;
  for (int i = 0; i < limit; i++) {
    exp = i % 2 == 0 ? 1 : -1;
    acc += exp * 1.0 / (i + 1);
  }
  return acc;
}

void scan_limit(int *limit) {
  printf("limit (zero or negative to exit): ");
  scanf("%d", limit);
}
