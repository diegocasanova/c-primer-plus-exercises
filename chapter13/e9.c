// Chapter 13 - Exercise 2
/* Write a file-copy program that takes the original filename and the copy file
 * from the command line. Use standard I/O and the binary mode, if possible.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

int main(void)
{
	FILE *fp;
	char words[MAX];
	int count = 0;

	if ((fp = fopen("wordy", "a+")) == NULL) {
		fprintf(stdout, "Can't open \"wordy\" file.\n");
		exit(EXIT_FAILURE);
	}

	rewind(fp);
	while (fgets(words, MAX, fp)) {
		count++;
	}

	puts("Enter words to add to the file; press the #");
	puts("key at the beginning of a line to terminate.");
	while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#')) {
		fprintf(fp, "%3d.%s\n", ++count, words);
	}

	puts("File contents:");
	rewind(fp); /* go back to beginning of file */
	while (fgets(words, MAX, fp) != NULL) {
		puts(words);
	}
	puts("Done!");

	if (fclose(fp) != 0) {
		fprintf(stderr, "Error closing file\n");
	}

	return 0;
}
