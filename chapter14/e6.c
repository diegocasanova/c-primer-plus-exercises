//Chapter 14 - Exercise 6
/* A text file holds information about a softball team. Each line has data arranged as follows:
4 Jessie Joybat 5 2 1 1
The first item is the player’s number, conveniently in the range 0–18. The second item is the player’s first name, and the third is the player’s last name. Each name is a single word. The next item is the player’s official times at bat, followed by the number of hits, walks, and runs batted in (RBIs). The file may contain data for more than one game,
so the same player may have more than one line of data, and there may be data for
other ps between those lines. Write a program that stores the data into an array of structures. The structure should have members to represent the first and last names, the at bats, hits, walks, and RBIs (runs batted in), and the batting average (to be calculated later). You can use the player number as an array index. The program should read to end- of-file, and it should keep cumulative totals for each player.
The world of baseball statistics is an involved one. For example, a walk or reaching base on an error doesn’t count as an at-bat but could possibly produce an RBI. But all this program has to do is read and process the data file, as described next, without worrying about how realistic the data is.
The simplest way for the program to proceed is to initialize the structure contents to zeros, read the file data into temporary variables, and then add them to the contents of the corresponding structure. After the program has finished reading the file, it should then calculate the batting average for each player and store it in the corresponding structure member. The batting average is calculated by dividing the cumulative number of hits for a player by the cumulative number of at-bats; it should be a floating-point calculation. The program should then display the cumulative data for each player along with a line showing the combined statistics for the entire team.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 30
#define PLAYERS 18
#define BUFF 50
#define FILE_PATT "%d %s %s %d %d %d %d"

struct player {
	char *name;
	char *surname;
	int number;
	int bat;
	int hits;
	int walks;
	int rbis;
	float bat_avg;
};

void load_file(FILE *fp, struct player *ps);
void print_ps(const struct player *ps);
void print_ply(const struct player *p);
float cal_avg(struct player *ps);
void cal_avgs(struct player *ps);

int main(int argc, char *argv[])
{
	struct player ps[PLAYERS];
	float bat_avg = 0;
	FILE *fp;

	if (argc < 2) {
		printf("Usage: %s filename\n", argv[0]);
		return EXIT_FAILURE;
	}

	if ((fp = fopen(argv[1], "r")) == NULL) {
		printf("Unable to open file\n");
		return EXIT_FAILURE;
	}
	rewind(fp);
	load_file(fp, ps);
	printf("file %s loaded!\n\n", argv[1]);
	bat_avg = cal_avg(ps);
	print_ps(ps);
	printf("Team bat avg: %.2f\n", bat_avg);

	if (fclose(fp)) {
		printf("Could not close file %s\n", argv[1]);
	}

	return EXIT_SUCCESS;
}

void load_file(FILE *fp, struct player *ps)
{
	struct player p;
	char name[NAME_LEN];
	char surname[NAME_LEN];

	while (fscanf(fp, FILE_PATT, &p.number, name, surname, &p.bat, &p.hits,
		      &p.walks, &p.rbis) == 7) {
		if (ps[p.number].name) {
			ps[p.number].bat += p.bat;
			ps[p.number].hits += p.hits;
			ps[p.number].bat += p.bat;
			ps[p.number].walks += p.walks;
			ps[p.number].rbis += p.rbis;
			continue;
		}
		ps[p.number] = p;
		ps[p.number].name = (char *)malloc(strlen(name) * sizeof(char));
		ps[p.number].surname =
			(char *)malloc(strlen(surname) * sizeof(char));
		strncpy(ps[p.number].name, name, strlen(name));
		strncpy(ps[p.number].surname, surname, strlen(surname));
	}
}

void print_ps(const struct player *ps)
{
	printf("Players: \n");
	for (int i = 0; i < PLAYERS && ps[i].name; i++)
		print_ply(&ps[i]);
}

void print_ply(const struct player *p)
{
	printf("%d - %s, %s\n", p->number, p->surname, p->name);
	printf("Official times at bat: %d\n", p->bat);
	printf("hits: %d\n", p->hits);
	printf("walks: %d\n", p->walks);
	printf("RBIs: %d\n", p->rbis);
	printf("Bat Avg: %.2f\n\n", p->bat_avg);
}

float cal_avg(struct player *ps)
{
	int bats = 0;
	int hits = 0;
	for (int i = 0; i < PLAYERS && ps[i].name; i++) {
		ps[i].bat_avg = (float)ps[i].hits / (float)ps[i].bat;
		bats += ps[i].bat;
		hits += ps[i].hits;
	}
	return (float)hits / (float)bats;
}

