// Chapter 13 - Exercise 2
/* Write a file-copy program that takes the original filename and the copy file
 * from the command line. Use standard I/O and the binary mode, if possible.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 256

int main(int argc, char *argv[])
{
	FILE *f_input = NULL;
	FILE *f_output = NULL;
	char line[LINE_SIZE];

	if (argc < 3) {
		printf("Usage: %s <filename source> <filename destination> \n",
		       argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((f_input = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Can't open the file '%s'\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((f_output = fopen(argv[2], "wb")) == NULL) {
		fprintf(stderr, "Can't open the file '%s'\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	while (fread(line, sizeof(char), LINE_SIZE, f_input) > 0) {
		fwrite(line, sizeof(char), LINE_SIZE, f_output);
	}

	fclose(f_input);
	fclose(f_output);

	return EXIT_SUCCESS;
}