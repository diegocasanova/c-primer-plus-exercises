// Chapter 13 - Exercise 3
/* Write a file copy program that prompts the user to enter the name of a text
 * file to act as the source file and the name of an output file. The program
 * should use the toupper() function from ctype.h to convert all text to
 * uppercase as it’s written to the output file. Use standard I/O and the text
 * mode.
 */

#include <stdio.h>
#include <stdlib.h>

#define FILENAME_SIZE 256

int main(void)
{
	FILE *f_input = NULL;
	FILE *f_output = NULL;
	char fname_input[FILENAME_SIZE];
	char fname_output[FILENAME_SIZE];
	char line[FILENAME_SIZE];

	printf("filename to copy: ");
	scanf("%s", fname_input);

	printf("destination filename: ");
	scanf("%s", fname_output);

	if ((f_input = fopen(fname_input, "rb")) == NULL) {
		fprintf(stderr, "Can't open the file '%s'\n", fname_input);
		exit(EXIT_FAILURE);
	}

	if ((f_output = fopen(fname_output, "wb")) == NULL) {
		fprintf(stderr, "Can't open the file '%s'\n", fname_output);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, FILENAME_SIZE, f_input) != NULL) {
		fputs(line, f_output);
	}

	fclose(f_input);
	fclose(f_output);

	return EXIT_SUCCESS;
}