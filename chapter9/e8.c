// Chapter 9 - exercise 8
/* Chapter 6, “C Control Statements: Looping,” (Listing 6.20) shows a power()
function that returned the result of raising a type double number to a positive
integer value. Improve the function so that it correctly handles negative
powers. Also, build into the function that 0 to any power other than 0 is 0 and
that any number to the 0 power is 1. (It should report that 0 to the 0 is
undefined, then say it’s using a value of 1.) Use a loop. Test the function in a
program.
 */
#include <ctype.h>
#include <stdio.h>

double power(double, int);
double negative_power(double, int);
int read_numbers(double *, int *);

int main(void) {

  double number = 0.0;
  int exp = 0;

  while (read_numbers(&number, &exp) == 2) {
    if (number == 0.0 && exp == 0) {
      printf("Undefined operation!!\n");
      continue;
    }
    printf("%lf ^ %d = %.2lf\n", number, exp, power(number, exp));
  }

  return 0;
}

double power(double number, int exp) {
  if (exp == 0) {
    return 1;
  }
  if (exp < 0) {
    return negative_power(number, exp);
  }
  double counter = 1;
  for (; exp >= 1; exp--) {
    counter *= number;
  }
  return counter;
}

double negative_power(double number, int exp) {
  return 1 / power(number, -exp);
}

int read_numbers(double *number, int *exp) {
  printf("number, exponent: ");
  return scanf("%lf,%d", number, exp);
}
