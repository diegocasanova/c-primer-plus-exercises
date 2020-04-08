/* 3. Devise a structure template that will hold the name of a month, 
*  a three-letter abbreviation for the month, the number of days in the month, and the month number.
*  4. Define an array of 12 structures of the sort in question 3 and initialize it for a non-leap year.
*/

#define MAX_NAME_LEN 10
#define SHORT_NAME_LEN 4

typedef enum {
	JANUARY,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
} months;

struct month_t {
	char name[MAX_NAME_LEN];
	char short_name[SHORT_NAME_LEN];
	int days;
	months month;
};

const struct month_t NON_LEAP_YEAR[] = {
	{ "January", "JAN", 31,  JANUARY},   { "February", "FEB", 28, FEBRUARY },
	{ "March", "MAR", 31, MARCH },     { "April", "APR", 30, APRIL },
	{ "May", "MAY", 31, MAY },       { "June", "JUN", 30, JUNE },
	{ "July", "JUL", 31, JULY },      { "August", "AGO", 31, AUGUST },
	{ "September", "SEP", 30, SEPTEMBER }, { "October", "OCT", 31, OCTOBER },
	{ "November", "NOV", 30, NOVEMBER }, { "December", "DEC", 31, DECEMBER }
};