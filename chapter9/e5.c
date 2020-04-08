// Chapter 9 - exercise 5
#include <stdio.h>

void larger_of(double *, double *);

int main(void) {

  double a, b;
  a = b = 0.0;

  printf("Enter two numbers: ");
  scanf("%lf %lf", &a, &b);
  larger_of(&a, &b);
  printf("larger: %lf %lf\n", a, b);
  getchar();

  return 0;
}

void larger_of(double *a, double *b) {
  double max = *a > *b ? *a : *b;
  *a = *b = max;
}
