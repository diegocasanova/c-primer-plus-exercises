// Chapter 14 - Exercise 8-9
/* The Colossus Airlines fleet consists of one plane with a seating capacity of 12. It makes one flight daily. Write a seating reservation program with the following features:
* a. The program uses an array of 12 structures. Each structure should hold a seat identification number, a marker that indicates whether the seat is assigned, the last name of the seat holder, and the first name of the seat holder.
* Key Concepts 671
* 672 Chapter 14 Structures and Other Data Forms
* b. The program displays the following menu:
* To choose a function, enter its letter label:
* a) Show number of empty seats
* b) Show list of empty seats
* c) Show alphabetical list of seats
* d) Assign a customer to a seat assignment e) Delete a seat assignment
* f) Quit
* c. The program successfully executes the promises of its menu. Choices d) and e) require additional input, and each should enable the user to abort an entry.
* d. After executing a particular function, the program shows the menu again, except for choice f).
* e. Data is saved in a file between runs. When the program is restarted, it first loads in the data, if any, from the file.
* * Colossus Airlines (from exercise 8) acquires a second plane (same capacity) and expands its service to four flights daily (Flights 102, 311, 444, and 519). Expand the program to handle four flights. Have a top-level menu that offers a choice of flights and the option to quit. Selecting a particular flight should then bring up a menu similar to that of exercise 8. However, one new item should be added: confirming a seat assignment. Also, the quit choice should be replaced with the choice of exiting to the top-level menu. Each display should indicate which flight is currently being handled. Also, the seat assignment display should indicate the confirmation status.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define BUFFER 30
#define PLANE_CAP 12
#define MAX_PLANE_ROW (PLANE_CAP / 2)
#define FLIGHTS 4

//Submenu options
#define EMPTY_SEATS 97
#define LIST_EMPTY_SEATS 98
#define LIST_ALPHA_SEATS 99
#define ASSIGN_CUSTOMER 100
#define DELETE_ASSIGNMENT 101
#define BACK_TO_MENU 102

const char *fligths[] = { "102", "311", "444", "519" };

struct seat {
	char *name;
	char *surname;
	char *id;
	bool assigned;
};

//Menu functions
char show_submenu(void);
int show_menu(void);
void eat_line(void);
void any_key();
void execute_option(struct seat fs[][PLANE_CAP], int f, int op);

// Seats logic
void init_seat(struct seat *s, int s_number);
void show_empty_seats(struct seat fs[][PLANE_CAP], int f);
void show_list_empty_seats(struct seat fs[][PLANE_CAP], int f);
void show_seat(const struct seat *s);
void unassigned_seat(struct seat *s);
void assign_seat(struct seat *seats);
bool validate_seat_input(int row, char col);

// loops functions
void process_flights_with_seat_number(struct seat fs[][PLANE_CAP],
				      void (*function)(struct seat *s,
						       int s_number));
void process_flights(struct seat fs[][PLANE_CAP],
		     void (*function)(struct seat *s));

//Cleanup
void free_seat(struct seat *s);

int main(void)
{
	struct seat fs[FLIGHTS][PLANE_CAP];
	int sel_flight = 0;
	int option = 0;

	process_flights_with_seat_number(fs, init_seat);

	while ((sel_flight = show_menu()) >= 0) {
		printf("Selected flight: [%s]\n\n", fligths[sel_flight]);
		do {
			option = show_submenu();
			printf("Selected option: [%c]\n\n", option);
			execute_option(fs, sel_flight, option);
		} while (option != BACK_TO_MENU);
	}
	process_flights(fs, free_seat);

	return EXIT_SUCCESS;
}

int show_menu(void)
{
	int flight = -1;
	do {
		puts("\nSelect flight:");
		for (int i = 0; i < FLIGHTS; i++) {
			printf("%d) %s\n", i + 1, fligths[i]);
		}
		puts("0) quit");
		printf("Option: ");
		scanf("%d", &flight);
		eat_line();
	} while (flight < 0 && flight > FLIGHTS);
	return flight - 1;
}

char show_submenu(void)
{
	char ans = '1';

	do {
		puts("\nEnter choice:");
		puts("a) Show number of empty seats");
		puts("b) Show list of empty seats");
		puts("c) Show alphabetical list of seats");
		puts("d) Assign a customer to a seat assignment");
		puts("e) Delete a seat assignment");
		puts("f) Return to main menu");
		printf("Option: ");
		ans = tolower(getchar());
		eat_line();
	} while (!strchr("abcdef", ans));
	return ans;
}

void execute_option(struct seat fs[][PLANE_CAP], int f, int op)
{
	switch (op) {
	case EMPTY_SEATS:
		show_empty_seats(fs, f);
		break;
	case LIST_EMPTY_SEATS:
		show_list_empty_seats(fs, f);
		break;
	case LIST_ALPHA_SEATS:
	case ASSIGN_CUSTOMER:
	case DELETE_ASSIGNMENT:
	case BACK_TO_MENU:
		return;
	}
}

void show_list_empty_seats(struct seat fs[][PLANE_CAP], int f)
{
	for (int i = 0; i < PLANE_CAP; i++)
		if (!fs[f][i].assigned)
			show_seat(&fs[f][i]);
}

void show_empty_seats(struct seat fs[][PLANE_CAP], int f)
{
	int c = 0;
	for (int i = 0; i < PLANE_CAP; i++)
		if (!fs[f][i].assigned)
			++c;
	printf("Flight [%s] -> Empty seats [%d]\n", fligths[f], c);
	any_key();
}

void show_seat(const struct seat *s)
{
	printf("SEAT: %s\n", s->id);
	if (s->assigned)
		printf("Assigned to : %s, %s\n", s->surname, s->name);
	else
		printf("Not Assigned!\n");
	printf("\n");
}

void eat_line(void)
{
	while (getchar() != '\n')
		continue;
}

void any_key(void)
{
	puts("Press any key to continue");
	eat_line();
}

void init_seat(struct seat *s, int s_number)
{
	char id[3];
	id[0] = (s_number / 2 + 1) + '0';
	id[1] = s_number % 2 == 0 ? 'A' : 'B';
	id[2] = '\0';
	s->id = (char *)malloc(3 * sizeof(char));
	strncpy(s->id, id, strlen(id));
	s->assigned = false;
}

void unassigned_seat(struct seat *s)
{
	if (strlen(s->name))
		free(s->name);
	if (strlen(s->surname))
		free(s->surname);
	s->assigned = false;
}

void free_seat(struct seat *s)
{
	unassigned_seat(s);
	free(s->id);
}

void process_flights_with_seat_number(struct seat fs[][PLANE_CAP],
				      void (*function)(struct seat *s,
						       int s_number))
{
	for (int j = 0; j < FLIGHTS; j++)
		for (int i = 0; i < PLANE_CAP; i++)
			function(&fs[j][i], i);
}

void process_flights(struct seat fs[][PLANE_CAP],
		     void (*function)(struct seat *s))
{
	for (int j = 0; j < FLIGHTS; j++)
		for (int i = 0; i < PLANE_CAP; i++)
			function(&fs[j][i]);
}

bool validate_seat_input(int row, char col)
{
	bool valid = false;
	if (row < 1 || row > PLANE_CAP / 2) {
		printf("Invalid row %d - Allowed 1 - %d\n", row, MAX_PLANE_ROW);
		valid = valid && false;
	}
	if (!strchr("AB", col)) {
		printf("Invalid seat %c - Allowed A|B\n", col);
		valid = valid && false;
	}
	return valid;
}

void assign_seat(struct seat *seats)
{
	int row = 1;
	char col = 'A';
	puts("\nEnter seat - format number seat (0 or CTRL-D to exit):");
	while (scanf("%d %c", &row, &col) == 2) {
		eat_line();
		row--;
		col = toupper(col);
		if (!validate_seat_input(row, col)) {
			puts("\nEnter seat - format number seat (0 or CTRL-D to exit):");
			continue;
		} else {
			if (!seats[row + col - 'A'].assigned) {
				puts("Seat already assigned!");
				continue;
			}
			break;
		}
	}
	//TODO: assign seat
}
