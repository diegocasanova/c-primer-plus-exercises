// Chapter 5 - review questions
#include <stdio.h>

void print_int_var(char *var_name, int value);

int main(void) {

  // question 12
  int x = 0;
  print_int_var("x", x);
  x += 10;

  print_int_var("x + 10", x);
  x++;
  print_int_var("x++ ", x);

  int a, b, c;
  a = 2;
  b = 3;
  c = 0;
  print_int_var("a", a);
  print_int_var("b", b);
  print_int_var("c", c);

  c = 2 * (a + b);
  print_int_var("2 * (a + b) ", c);
  c = a + 2 * b;
  print_int_var("a + 2*b", c);

  return 0;
}

void print_int_var(char *var_name, int value) {
  printf("%s=%d\n", var_name, value);
}