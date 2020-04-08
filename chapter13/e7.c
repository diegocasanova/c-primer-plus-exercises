// Chapter 13 - Exercise 7
/* Write a program that opens two files. You can obtain the filenames either by
 * using command-line arguments or by soliciting the user to enter them. Have
 * the program print line 1 of the first file, line 1 of the second file, line 2
 * of the first file, line 2 of the second file, and so on, until the last line
 * of the longer file (in terms of lines) is printed.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 256

int main(int argc, char *argv[])
{
	FILE *f1 = NULL;
	FILE *f2 = NULL;
	char line1[LINE_SIZE];
	char line2[LINE_SIZE];

	if (argc < 3) {
		printf("Usage: %s <filename 1> <filename 2> \n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((f1 = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Can't open the file '%s'\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((f2 = fopen(argv[2], "r")) == NULL) {
		fprintf(stderr, "Can't open the file '%s'\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line1, LINE_SIZE, f1) != NULL &&
	       fgets(line2, LINE_SIZE, f2) != NULL) {
		puts(line1);
		puts(line2);
	}

	if (feof(f1)) {
		while (fgets(line2, LINE_SIZE, f2) != NULL) {
			puts(line2);
		}
	}

	if (feof(f2)) {
		while (fgets(line1, LINE_SIZE, f1) != NULL) {
			puts(line1);
		}
	}

	fclose(f1);
	fclose(f2);

	return EXIT_SUCCESS;
}