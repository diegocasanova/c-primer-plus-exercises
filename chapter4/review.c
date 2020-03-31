// Chapter 4 - review questions
#include <stdio.h>

#define BOOK "War and Peace"

int main(void) {
  float cost = 12.99;
  float percent = 80.0;

  // Question 5
  printf("This copy of \"%s\" sells for $%2.2f.\n", BOOK, cost);
  printf("That is %2.0f%% of list.\n", percent);

  // Question 9
  int first, third, fourth;
  float first_float, second_float;
  char linguini[10];
  char catch[10];

  scanf("%d", &first);
  scanf("%f %e", &second_float, &first_float);
  scanf("%s", linguini);
  scanf("%s %d", catch, &third);
  scanf("%*s %d", &fourth);

  printf("%d\n", first);
  printf("%f %e\n", second_float, first_float);
  printf("%s\n", linguini);
  printf("%s %d\n", catch, third);
  printf("%d\n", fourth);

  return 0;
}