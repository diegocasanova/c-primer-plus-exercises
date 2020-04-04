// Chapter 13 - Exercise 12
/* Create a text file consisting of 20 rows of 30 integers. The integers should
 * be in the range 0–9 and be separated by spaces. The file is a digital
 * representation of a picture, with the values 0 through 9 representing
 * increasing levels of darkness. Write a program that reads the contents of the
 * file into a 20-by-30 array of ints. In a crude approach toward converting
 * this digital representation to a picture, have the program use the values in
 * this array to initialize a 20-by-31 array of chars, with a 0 value
 * corresponding to a space character, a 1 value to the period character, and so
 * on, with each larger number represented by a character that occupies more
 * space. For example, you might use # to represent 9. The last character (the
 * 31st) in each row should be a null character, making it an array of 20
 * strings. Have the program display the resulting picture (that is, print the
 * strings) and also store the result in a text file.
 *
 * Digital images, particularly those radioed back from spacecraft, may have
 * glitches. Add a de-glitching function to programming exercise 12. It should
 * compare each value to its immediate neighbors to the left and right, above
 * and below. If the value differs by more than 1 from each of its neighbors,
 * replace the value with the average of the neighboring values. You should
 * round the average to the nearest integer value. Note that the points along
 * the boundaries have fewer than four neighbors, so they require special
 * handling.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_LINE 60
#define X 30
#define Y 20

static const char repr[9] = { '.', '!', '=', '*', '$', '&', '%', '#', '@' };

void read_nums(int nums[Y][X], FILE *file);
void parse_line(int nums[Y][X], char *line, int y);
void print_line(const int *arr_start, int size);
void print_nums(const int arr[Y][X]);
void transform(int nums[Y][X], char conv[Y][X + 1]);
int deglitch(int nums[Y][X]);
void print_result(char conv[Y][X + 1]);
void save(char conv[Y][X + 1], FILE *fp);
int count_adjacent(int x, int y);

int main(int argc, char *argv[])
{
	FILE *f_input = NULL;
	FILE *f_output = NULL;
	int nums[Y][X];
	char conv[Y][X + 1];

	if (argc < 3) {
		printf("Usage: %s <filename>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((f_input = fopen(argv[1], "rb")) == NULL) {
		fprintf(stdout, "Can't open '%s' file.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((f_output = fopen(argv[2], "w")) == NULL) {
		fprintf(stdout, "Can't open '%s' file.\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	read_nums(nums, f_input);
	print_nums(nums);
	transform(nums, conv);
	print_result(conv);
	printf("De-glitched points [%d]\n", deglitch(nums));
	print_nums(nums);
	transform(nums, conv);
	print_result(conv);
	save(conv, f_output);

	if (fclose(f_input) != 0)
		fprintf(stderr, "Error closing input file\n");

	if (fclose(f_output) != 0)
		fprintf(stderr, "Error closing output file\n");

	return 0;
}

void read_nums(int nums[Y][X], FILE *file)
{
	char line[FILE_LINE];
	int y = 0;
	while (fread(line, sizeof(char), FILE_LINE, file))
		parse_line(nums, line, y++);
}

void parse_line(int nums[Y][X], char *line, int y)
{
	int x = 0;
	for (int i = 0; i < FILE_LINE; i++) {
		if (!isspace(line[i]))
			nums[y][x++] = line[i] - '0'; //ascii to int
	}
}

int deglitch(int nums[Y][X])
{
	int count, count_n, count_d, sum;
	count = count_n = count_d = sum = 0;

	for (int j = 0; j < Y; j++) {
		for (int i = 0; i < X; i++) {
			count_d = sum = 0;

			if ((i - 1 >= 0) &&
			    (abs(nums[j][i - 1] - nums[j][i]) > 1)) {
				count_d++;
				sum += nums[j][i - 1];
			}

			if ((j - 1 >= 0) &&
			    (abs(nums[j - 1][i] - nums[j][i]) > 1)) {
				count_d++;
				sum += nums[j - 1][i];
			}

			if ((i + 1 < X) &&
			    (abs(nums[j][i + 1] - nums[j][i]) > 1)) {
				count_d++;
				sum += nums[j][i + 1];
			}

			if ((j + 1 < Y) &&
			    (abs(nums[j + 1][i] - nums[j][i]) > 1)) {
				count_d++;
				sum += nums[j + 1][i];
			}

			count_n = count_adjacent(i, j);

			if (count_n - count_d == 0) {
				count++;
				nums[j][i] = sum / count_n;
			}
		}
	}

	return count;
}

void transform(int nums[Y][X], char conv[Y][X + 1])
{
	for (int j = 0; j < Y; j++) {
		for (int i = 0; i < X; i++) {
			if (nums[j][i] == 0)
				conv[j][i] = ' ';
			else
				conv[j][i] = repr[nums[j][i] - 1];
		}
		conv[j][X] = '\0';
	}
}

void print_line(const int *arr_start, int size)
{
	printf("[");
	for (int i = 0; i < size; i++)
		printf(" %d ", arr_start[i]);
	printf("]\n");
}

void print_nums(const int arr[Y][X])
{
	for (int j = 0; j < Y; j++)
		print_line(arr[j], X);
}

void print_result(char conv[Y][X + 1])
{
	for (int i = 0; i < Y; i++)
		puts(conv[i]);
}

void save(char conv[Y][X + 1], FILE *fp)
{
	for (int i = 0; i < Y; i++)
		fprintf(fp, "%s\n", conv[i]);
}

int count_adjacent(int x, int y)
{
	if (x > 0 && x < X - 1 && y > 0 && y < Y - 1)
		return 4;

	if ((x == 0 && y == 0) || (x == X - 1 && y == Y - 1) ||
	    (x == X - 1 && y == 0) || (x == 0 && y == Y - 1)) // corners
		return 2;

	return 3;
}