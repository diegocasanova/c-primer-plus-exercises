// Chapter 13 -
/* Generates a binary file with floating point numbers
 */

#include <stdio.h>
#include <stdlib.h>

#define FILENAME "text_numbers.dat"

int main(int argc, char *argv[])
{
	FILE *f_output;
	float number;
	int elements;

	if (argc < 2) {
		printf("Usage: %s <number of elements>", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((f_output = fopen(FILENAME, "w")) == NULL) {
		fprintf(stderr, "Couldn't open the file");
		exit(EXIT_FAILURE);
	}

	elements = atoi(argv[1]);

	for (int i = 0; i < elements; i++) {
		number = 100.0 * i + 1.0 / (i + 1);
		fprintf(f_output, "%.2f ", number);
		fprintf(stdout, "%.2f\n", number);
	}

	fclose(f_output);

	return EXIT_SUCCESS;
}