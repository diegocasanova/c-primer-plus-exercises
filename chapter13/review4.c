// Chapter 13 - Review 4
/* Write a program that takes zero command-line arguments or one command-line
 * argument. If there is one argument, it is interpreted as the name of a file.
 * If there is no argument, the standard input (stdin) is to be used for input.
 * Assume that the input consists entirely of floating-point numbers. Have the
 * program calculate and report the arithmetic mean (the average) of the input
 * numbers.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *f_input;
	float value;
	float sum = 0;
	int count = 0;

	if (argc < 2)
		f_input = stdin;
	else
		f_input = fopen(argv[1], "rb");

	if (f_input == NULL) {
		fprintf(stderr, "Couldn't open the file");
		exit(EXIT_FAILURE);
	}

	printf("file opened!\n");
	while (fscanf(f_input, "%f ", &value) == 1) {
		printf("%.2f\n", value);
		count++;
		sum += value;
	}

	printf("elements: %d - mean: %.2f\n", count, sum / count);
	fclose(f_input);

	return EXIT_SUCCESS;
}