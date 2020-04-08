#include <stdio.h>

#define SPACE ' '

int min(int, int);
void chline(char, int, int);
void print_char(char, int);

int main(void) {

  // Exercise 1
  int a, b;
  a = b = 0;

  printf("Enter two numbers: ");
  scanf("%d %d", &a, &b);
  printf("min: %d\n", min(a, b));
  getchar();

  // Exercise 2
  char ch = ' ';
  int i, j;

  printf("Enter a char: ");
  scanf("%c", &ch);
  printf("Enter col i and j: ");
  scanf("%d %d", &i, &j);
  chline(ch, i, j);

  return 0;
}

int min(int a, int b) { return a <= b ? a : b; }

void chline(char ch, int from, int to) {
  print_char(SPACE, from);
  print_char(ch, to - from);
  printf("\n");
}

void print_char(char ch, int times) {
  for (int i = 0; i < times; i++) {
    printf("%c", ch);
  }
}
