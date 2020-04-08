// Chapter 4 - exercise 6 - basic IO
#include <float.h>
#include <stdio.h>

int main(void) {

  float float_number = 1.0 / 3.0;
  double double_number = 1.0 / 3.0;

  printf("FLT_DIG = %d\n", FLT_DIG);
  printf("DBL_DIG = %d\n\n", DBL_DIG);

  printf("float\n");
  printf("%.4f\n%.12f\n%.16f\n", float_number, float_number, float_number);
  printf("\ndouble\n");
  printf("%.4f\n%.12f\n%.16f\n", double_number, double_number, double_number);

  return 0;
}
