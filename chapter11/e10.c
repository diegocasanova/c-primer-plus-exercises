// Chapter 11 - exercise 10
/* Write a function that takes a string as an argument and removes the spaces
 * from the string. Test it in a program that uses a loop to read lines until
 * you enter an empty line. The program should apply the function to each input
 * string and display the result.
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define STR_SIZE 50

char *read_str(char *str, unsigned int size);
bool is_break_line(char ch);
void remove_spaces(char *str);
void move_chars(char *str);

int main(void) {

  char str[STR_SIZE];

  while (read_str(str, STR_SIZE)) {
    remove_spaces(str);
    printf("with no spaces: %s\n", str);
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

bool is_break_line(char ch) { return (ch == EOF || ch == '\n'); }

void remove_spaces(char *str) {
  while (*str) {
    if (isspace(*str)) {
      move_chars(str);
    }
    str++;
  }
}

void move_chars(char *str) {
  while (*str) {
    *str = *(str + 1);
    str++;
  }
}