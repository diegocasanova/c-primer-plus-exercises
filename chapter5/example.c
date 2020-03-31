// Chapter 5 - examples
#include <stdio.h>

int main(void) {

  int index = 96;
  while (index++ < 103) {
    printf("index = %d\n", index);
    printf("ascii = %c\n", index);
  }

  char chr = 'a';
  while (chr <= 'z') {
    printf("%5c", chr++);
  }
  printf("\n");

  char ch;
  int i;
  float fl;
  fl = i = ch = 'C';
  printf("ch = %c, i = %d, fl = %2.2f\n", ch, i, fl);
  ch = ch + 1;
  i = fl + 2 * ch;
  fl = 2.0 * ch + i;
  printf("ch = %c, i = %d, fl = %2.2f\n", ch, i, fl);
  ch = 1107;
  printf("Now ch = %c, i = %d\n", ch, ch);
  ch = 80.89;
  printf("Now ch = %c, i = %d\n", ch, ch);

  int int_test;

  int_test = 5.89;

  printf("int_test = %d, as float %.2f\n", int_test, int_test);

  int x = 3 / 5 * 22.0;
  printf("x = %d\n", x);

  x = 100;
  while (x++ < 103) {
    printf("%4d\n", x);
  }
  printf("out of the while loop!\n");
  printf("%4d\n", x);

  return 0;
}