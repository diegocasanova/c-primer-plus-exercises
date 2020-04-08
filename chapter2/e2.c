// C primer plus - Exercises chapter 2
#include <stdio.h>

void jolly(void);
void deny(void);
void br(void);
void ic(void);
void smile(void);
void one_three(void);
void two(void);
void print_exercise(int);

int main(void) {

  // exercise 1
  print_exercise(1);
  printf("Diego Casanova\n");
  printf("Diego\nCasanova\n");
  printf("Diego ");
  printf("Casanova\n");

  // exercise 2
  print_exercise(2);
  printf("Diego Casanova\nFake Address 147\n");

  // exercise 3
  print_exercise(3);
  printf("35 years ~ %d days\n", 35 * 365);

  // exercise 4
  print_exercise(4);
  jolly();
  jolly();
  jolly();
  deny();

  // exercise 5
  print_exercise(5);
  br();
  printf(", ");
  ic();
  printf("\n");
  ic();
  printf(",\n");
  br();
  printf("\n");

  // exercise 6
  print_exercise(6);
  int toes = 10;
  printf("toes = %d\n2 * toes = %d\ntoes * toes = %d\n", toes, 2 * toes,
         toes * toes);

  // exercise 7
  print_exercise(7);
  smile();
  smile();
  smile();
  printf("\n");
  smile();
  smile();
  printf("\n");
  smile();
  printf("\n");

  // exercise 8
  print_exercise(8);
  printf("staring now:\n");
  one_three();
  printf("done!\n");
}

void print_exercise(int exercise) {
  printf("\n------ Exercise %d ------\n", exercise);
}

void jolly(void) { printf("For he's a jolly good fellow!\n"); }

void deny(void) { printf("Which nobody can deny!\n"); }

void br(void) { printf("Brazil, Russia"); }

void ic(void) { printf("India, China"); }

void smile(void) { printf("Smile!"); }

void one_three(void) {
  printf("one\n");
  two();
  printf("three\n");
}

void two(void) { printf("two\n"); }
