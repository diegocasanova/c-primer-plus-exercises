// Chapter 11 - exercise 11
/* Write a program that reads in up to 10 strings or to EOF, whichever comes
 * first. Have it offer the user a menu with five choices: print the original
 * list of strings, print the strings in ASCII collating sequence, print the
 * strings in order of increasing length, print the strings in order of the
 * length of the first word in the string, and quit. Have the menu recycle until
 * the user enters the quit request. The program, of course, should actually
 * perform the promised tasks.
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_STR 10
#define MAX_LEN 50

#define AS_IS 1
#define ASC_ASCII 2
#define ASC_LEN 3
#define ASC_FWORD_LEN 4
#define QUIT 5

char *read_str(char *str, unsigned int size, int string_num);
void print_strings(char *strings[]);
int read_option();
bool valid_option(int option);
void print_asterisks();
void sort(char *strings[], int (*cmp)(const char *str1, const char *str2));
int cmp_by_length(const char *str1, const char *str2);
int cmp_by_fword_length(const char *str1, const char *str2);
size_t fword_len(const char *str);
size_t cmp(size_t a, size_t b);

int main(void) {

  char strs[MAX_STR][MAX_LEN];
  char *ptrs[MAX_STR];
  int option;

  int count = 0;
  printf("Enter strings (max %d) or empty line to quit\n", MAX_STR);
  while (count < MAX_STR && (read_str(strs[count], MAX_LEN, count)) != NULL) {
    ptrs[count] = strs[count];
    count++;
  }
  while ((option = read_option()) != QUIT) {
    switch (option) {
    case AS_IS:
      print_strings(ptrs);
      break;
    case ASC_ASCII:
      sort(ptrs, strcmp);
      print_strings(ptrs);
      break;
    case ASC_LEN:
      sort(ptrs, cmp_by_length);
      print_strings(ptrs);
      break;
    case ASC_FWORD_LEN:
      sort(ptrs, cmp_by_fword_length);
      print_strings(ptrs);
      break;
    default:
      break;
    }
    printf("Press any key to continue");
    getchar();
    getchar();
  }
  puts("Bye!");
  return 0;
}

void print_asterisks() {
  printf("**************************************************************\n");
}

bool valid_option(int option) {
  return (option == 1 || option == 2 || option == 3 || option == 4 ||
          option == 5);
}

int read_option() {
  int option = 0;
  do {
    print_asterisks();
    printf(
        "Enter the number corresponding to the desired pay rate or action:\n");
    printf("%d) print original\n", AS_IS);
    printf("%d) print ASCII ascending\n", ASC_ASCII);
    printf("%d) print in order of increasing length\n", ASC_LEN);
    printf("%d) print in order length of the first word\n", ASC_FWORD_LEN);
    printf("%d) quit\n", QUIT);
    print_asterisks();
    printf("Option: ");
    scanf("%d", &option);
    if (!valid_option(option)) {
      printf("Invalid option!\n");
      getchar();
    }
  } while (!valid_option(option));

  return option;
}

void print_strings(char *strings[]) {
  for (int i = 0; i < MAX_STR && strings[i] != NULL; i++) {
    puts(strings[i]);
  }
}

char *read_str(char *str, unsigned int size, int string_num) {
  int count = 0;
  printf("string[%d]: ", string_num);
  if (fgets(str, size, stdin) == NULL || str[0] == '\n') {
    return NULL;
  }

  while (str[count] != '\n' && str[count] != '\0') {
    count++;
  }

  if (str[count] == '\n') {
    str[count] = '\0';
  } else {
    while (getchar() != '\n') {
      continue;
    }
  }
  return str;
}

void sort(char *strings[], int (*cmp)(const char *str1, const char *str2)) {
  for (int i = 0; strings[i] && i < MAX_STR; i++) {
    for (int j = i + 1; strings[j] && j < MAX_STR; j++) {
      if ((*cmp)(strings[j], strings[i]) < 0) {
        char *temp = strings[j];
        strings[j] = strings[i];
        strings[i] = temp;
      }
    }
  }
}

int cmp_by_length(const char *str1, const char *str2) {
  return cmp(strlen(str1), strlen(str2));
}

int cmp_by_fword_length(const char *str1, const char *str2) {
  return cmp(fword_len(str1), fword_len(str2));
}

size_t fword_len(const char *str) {
  size_t count = 0;
  while (str[count] != '\0' && !isspace(str[count])) {
    count++;
  }
  return count;
}

size_t cmp(size_t a, size_t b) {
  if (a == b) {
    return 0;
  }
  return a < b ? -1 : 1;
}