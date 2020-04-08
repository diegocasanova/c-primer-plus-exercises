// Chapter 13 - Review 5
/* Write a program that takes two command-line arguments. The first is a
 * character, and the second is a filename. The program should print only those
 * lines in the file containing the given character.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 256

int main(int argc, char *argv[])
{
	FILE *f1 = NULL;
	char line1[LINE_SIZE];

	if (argc < 3) {
		printf("Usage: %s <char> <filename> \n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((f1 = fopen(argv[2], "r")) == NULL) {
		fprintf(stderr, "Can't open the file '%s'\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line1, LINE_SIZE, f1) != NULL) {
		if (strchr(line1, argv[1][0])) {
			puts(line1);
		}
	}

	fclose(f1);

	return EXIT_SUCCESS;
}