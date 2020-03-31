// Chapter 5 - Exercise 1 - Operators
#include <stdio.h>

#define MSG "Enter minutes (<1 to exit): "
#define MINS_PER_HOUR 60

int read_minutes(void);
void print_hours_mins(int mins);

int main(void) {

  int mins = read_minutes();

  while (mins > 0) {
    print_hours_mins(mins);
    mins = read_minutes();
  }

  return 0;
}

int read_minutes(void) {
  int mins = 0;
  printf(MSG);
  scanf("%d", &mins);
  return mins;
}

void print_hours_mins(int mins) {
  printf("hours: %d, minutes: %d\n", mins / MINS_PER_HOUR,
         mins % MINS_PER_HOUR);
}