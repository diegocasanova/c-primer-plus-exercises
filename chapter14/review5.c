/* Write a function that, when given the month number, returns the total days in the year
up to and including that month. Assume that the structure template of question 3 and
an appropriate array of such structures are declared externally.*/

#include <stdio.h>
#include <stdlib.h>
#include "month.h"

extern const struct month_t NON_LEAP_YEAR[];
int days_until(months m);
months get_month();

int main(void)
{
	months m;	
	m = get_month();

	printf("Days up to %s: %d\n", NON_LEAP_YEAR[m].name, days_until(m));

	return EXIT_SUCCESS;
}

int days_until(months m)
{
	int c = 0;
	for (int i = 0; i <= m; i++)
		c += NON_LEAP_YEAR[i].days;
	return c;
}

months get_month()
{
	int m;
	printf("Month: ");
	scanf("%d", &m);
	m--;
	while (m < JANUARY || m > DECEMBER) {
		printf("Invalid month!\n");
		printf("Month: ");
		scanf("%d", &m);
		m--;
	}
	return NON_LEAP_YEAR[m].month;
}