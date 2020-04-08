// Chapter 11 - exercise 9
/* Write a function that replaces the contents of a string with the string
 * reversed. Test the function in a complete program that uses a loop to provide
 * input values for feeding to the function.
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define STR_SIZE 50

char *read_str(char *str, unsigned int size);
bool is_break_line(char ch);
void reverse_str(char *str);

int main(void) {

  char str[STR_SIZE];

  while (read_str(str, STR_SIZE)) {
    reverse_str(str);
    printf("reversed: %s\n", str);
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

void reverse_str(char *str) {
  char ch;
  int i, j;
  i = 0;
  j = strlen(str) - 1;
  for (; i < j; i++, j--) {
    ch = str[j];
    str[j] = str[i];
    str[i] = ch;
  }
}