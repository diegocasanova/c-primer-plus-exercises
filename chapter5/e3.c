// Chapter 5 - Exercise 3 - Operators
#include <stdio.h>

#define MSG "Enter the number of days (<1 to exit): "
#define DAYS_PER_WEEK 7
#define DAYS "days"
#define DAY "day"
#define WEEKS "weeks"
#define WEEK "week"

int read_days(void);
void print_weeks(int days);

int main(void) {

  int days = read_days();

  while (days > 0) {
    print_weeks(days);
    days = read_days();
  }

  return 0;
}

int read_days(void) {
  int days = 0;
  printf(MSG);
  scanf("%d", &days);
  return days;
}

void print_weeks(int days) {
  int weeks = days / DAYS_PER_WEEK;
  int days_rem = days % DAYS_PER_WEEK;
  printf("%d days are %d %s, %d %s\n", days, weeks, weeks > 1 ? WEEKS : WEEK,
         days_rem, days_rem > 1 ? DAYS : DAY);
}