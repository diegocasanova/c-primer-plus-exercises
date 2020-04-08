//Chapter 14 - Exercise 5
/* Write a program that fits the following recipe:
* a. Externally define a name structure template with two members: a string to hold the
*    first name and a string to hold the second name.
* b. Externally define a student structure template with three members: a name
*    structure, a grade array to hold three floating-point scores, and a variable to hold
*    the average of those three scores.
* c. Have the main() function declare an array of CSIZE (with CSIZE = 4) student
*    structures and initialize the name portions to names of your choice. Use functions
*    to perform the tasks described in parts d., e., f., and g.
* d. Interactively acquire scores for each student by prompting the user with a student
*    name and a request for scores. Place the scores in the grade array portion of the
*    appropriate structure. The required looping can be done in main() or in the
*    function, as you prefer.
* e. Calculate the average score value for each structure and assign it to the proper
*    member.
* f. Print the information in each structure.
* g. Print the class average for each of the numeric structure members
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LEN 30
#define GRADES_LEN 3
#define CSIZE 4

struct name {
	char name[MAX_NAME_LEN];
	char surname[MAX_NAME_LEN];
};

struct student {
	struct name name;
	float grades[GRADES_LEN];
	float avg;
};

float calc_avg(const float *grades);
void calc_student_avgs(struct student *students);
float calc_class_avg(const struct student *students);
void print_student(const struct student *student);
void print_students(const struct student *students);
void fill_grades(struct student *student);
void fill_students_grades(struct student *students);

int main(void)
{
	struct student students[CSIZE] = { { .name = { "Fake1", "Student1" } },
					   { .name = { "Fake2", "Student2" } },
					   { .name = { "Fake3", "Student3" } },
					   { .name = { "Fake4",
						       "Student4" } } };

	fill_students_grades(students);
	calc_student_avgs(students);
	print_students(students);

	printf("\nClass average [%.2f]\n", calc_class_avg(students));

	return EXIT_SUCCESS;
}

float calc_avg(const float *grades)
{
	float s = 0;
	for (int i = 0; i < GRADES_LEN; i++)
		s += grades[i];
	return s / GRADES_LEN;
}

void calc_student_avgs(struct student *students)
{
	for (int i = 0; i < CSIZE; i++)
		students[i].avg = calc_avg(students[i].grades);
}

float calc_class_avg(const struct student *students)
{
	float s = 0;
	for (int i = 0; i < CSIZE; i++)
		s += students[i].avg;
	return s / CSIZE;
}

void print_student(const struct student *student)
{
	printf("\nName: %s, %s\n", student->name.surname, student->name.name);
	printf("Grades: [");
	for (int i = 0; i < GRADES_LEN; i++)
		printf(" %.2f ", student->grades[i]);
	printf("]\n");
	printf("Avg: %.2f\n", student->avg);
}

void print_students(const struct student *students)
{
	for (int i = 0; i < CSIZE; i++)
		print_student(&students[i]);
}

void fill_grades(struct student *student)
{
	printf("Insert %d grades for student [%s, %s]\n", GRADES_LEN,
	       student->name.surname, student->name.name);
	for (int i = 0; i < GRADES_LEN; i++)
		scanf("%f", &student->grades[i]);
	while (getchar() != '\n')
		continue;
}

void fill_students_grades(struct student *students)
{
	for (int i = 0; i < CSIZE; i++)
		fill_grades(&students[i]);
}

void test()
{
	printf("probando\n");
}
