// Chapter 11 - exercise 5
/* Design and test a function that searches the string specified by the first
 * function parameter for the first occurrence of a character specified by the
 * second function parameter. Have the function return a pointer to the
 * character if successful, and a null if the character is not found in the
 * string. (This duplicates the way that the library strchr() function works.)
 * Test the function in a complete program that uses a loop to provide input
 * values for feeding to the function.
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define STR_SIZE 10

char *read_str(char *str, unsigned int size);
bool is_break_line(char ch);
const char *str_chr(const char *arr, char chr);

int main(void) {

  char str[STR_SIZE];
  char ch;
  const char *found;

  while (read_str(str, STR_SIZE)) {
    printf("char: ");
    ch = getchar();

    if ((found = str_chr(str, ch)) != NULL) {
      printf("Character found!! -> ...\"%s\"\n", found);
    } else {
      puts("Character not found!");
    }
    getchar();
  }

  puts("Bye!");
  return 0;
}

char *read_str(char *str, unsigned int size) {
  char ch;
  int count = 0;

  printf("input: ");
  while ((ch = getchar()) != EOF && isspace(ch)) {
    continue;
  }
  if (ch == EOF) {
    return NULL;
  }
  *str++ = ch;
  count++;

  while (!is_break_line(ch = getchar()) && ch != EOF && count < size) {
    *str++ = ch;
    count++;
  }
  *str = '\0';
  while (ch != '\n') {
    ch = getchar();
  }
  return str;
}
bool is_break_line(char ch) {
  return (ch == '\n' || ch == EOF || ch == ' ' || ch == '\t');
}

const char *str_chr(const char *str, char chr) {
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == chr) {
      return str + i;
    }
  }
  return NULL;
}