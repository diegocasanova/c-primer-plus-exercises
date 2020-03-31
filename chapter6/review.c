// Chapter 6 - Review questions
#include <stdio.h>

#define ROWS 4
#define COLS 8
#define SIGN '$'

void print_row();
void print_question(int);
void question_6();
void question_8();
void question_10();

int main(void) {
  question_6();
  question_8();
  question_10();

  return 0;
}

void question_8() {
  print_question(8);
  char ch;
  scanf("%c", &ch);
  while (ch != 'g') {
    printf("%c", ++ch);
    scanf("%c", &ch);
  }
  printf("\n");
}

void question_6() {
  print_question(6);
  for (int i = 0; i < ROWS; i++) {
    print_row();
  }
}

void question_10() {
  print_question(10);
  double mint[10];

  scanf("%lf", &mint[2]);
  printf("%lf\n", mint[2]);
}

void print_question(int number) { printf("***Question %d***\n", number); }

void print_row() {
  for (int i = 0; i < COLS; i++) {
    printf("%c", SIGN);
  }
  printf("\n");
}