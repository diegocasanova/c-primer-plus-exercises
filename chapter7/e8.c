// Chapter 7 - Exercise 8
#include <stdbool.h>
#include <stdio.h>

#define PAY_RATE_1 8.75
#define PAY_RATE_2 9.33
#define PAY_RATE_3 10.00
#define PAY_RATE_4 11.20

#define TAX_RATE_1 0.15
#define TAX_RATE_2 0.20
#define TAX_RATE_3 0.25

#define MAX_TAX_RATE_1 300
#define MAX_TAX_RATE_2 150
#define MAX_SUM_TAX_RATE MAX_TAX_RATE_1 + MAX_TAX_RATE_2

#define OVERTIME_MIN 40
#define OVERTIME_RATE 1.5

float calculate_taxes(float);
float calculate_overtime(float, unsigned int);
float get_rate_from_option(int);
bool valid_option(int);
void print_asterisks();
int read_option();

int main(void) {
  int option = 0;
  while ((option = read_option()) != 5) {
    float rate, taxes, gross, overtime;
    unsigned int hours;
    taxes = gross = overtime = 0;

    rate = get_rate_from_option(option);
    printf("Hours worked: ");
    scanf("%d", &hours);
    gross = hours * rate;
    taxes = calculate_taxes(gross);
    overtime = calculate_overtime(rate, hours);

    printf("Gross pay: $%.2f\n", gross + overtime);
    printf("Overtime pay: $%.2f\n", overtime);
    printf("Taxes: $%.2f\n", taxes);
    printf("Net pay: $%.2f\n", gross - taxes);
    getchar();
    getchar();
  }
  return 0;
}

float calculate_overtime(float rate, unsigned int hours) {
  if (hours <= OVERTIME_MIN) {
    return 0;
  }
  return ((hours - OVERTIME_MIN) * OVERTIME_RATE * rate);
}

float calculate_taxes(float gross) {
  if (gross <= MAX_TAX_RATE_1) {
    return gross * TAX_RATE_1;
  }

  if (gross <= MAX_SUM_TAX_RATE) {
    return (MAX_TAX_RATE_1 * TAX_RATE_1) +
           (MAX_TAX_RATE_2 * (gross - MAX_TAX_RATE_1));
  }

  return (TAX_RATE_1 * MAX_TAX_RATE_1) + (TAX_RATE_2 * MAX_TAX_RATE_2) +
         (gross - MAX_SUM_TAX_RATE) * TAX_RATE_3;
}

float get_rate_from_option(int option) {
  float rate;
  switch (option) {
  case 1:
    rate = PAY_RATE_1;
    break;
  case 2:
    rate = PAY_RATE_2;
    break;
  case 3:
    rate = PAY_RATE_3;
    break;
  case 4:
    rate = PAY_RATE_4;
    break;
  }
  printf("Selected rate: $%.2f\n", rate);
  return rate;
}

void print_asterisks() {
  printf("**************************************************************\n");
}

bool valid_option(int option) {
  return (option == 1 || option == 2 || option == 3 || option == 4 ||
          option == 5);
}

int read_option() {
  int option = 0;
  do {
    print_asterisks();
    printf(
        "Enter the number corresponding to the desired pay rate or action:\n");
    printf("1) $%2.2f/hr\t\t\t\t2) $%2.2f/hr\n", PAY_RATE_1, PAY_RATE_2);
    printf("3) $%2.2f//hr\t\t\t\t4) $%2.2f/hr\n", PAY_RATE_3, PAY_RATE_4);
    printf("5) Quit\n");
    print_asterisks();
    printf("Option: ");
    scanf("%d", &option);
    if (!valid_option(option)) {
      printf("Invalid option!\n");
      getchar();
      getchar();
    }
  } while (!valid_option(option));

  return option;
}
