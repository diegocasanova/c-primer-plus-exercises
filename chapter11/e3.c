// Chapter 11 - exercise 3
/* Design and test a function that reads the first word from a line of input
 * into an array and discards the rest of the line. It should skip over leading
 * whitespace. Define a word as a sequence of characters with no blanks, tabs,
 * or newlines in it. Use getchar()
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define STR_SIZE 10

char *read_str(char *str, unsigned int size);
bool is_break_line(char ch);
void print_str(const char *str);

int main(void) {

  char str[STR_SIZE];

  while ((read_str(str, STR_SIZE)) != NULL) {
    puts("line:");
    puts(str);
    print_str(str);
    printf("length: %lu\n", strlen(str));
    printf("size of str: %lu\n", sizeof(str));
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
  return (ch == '\n' || ch == EOF || isspace(ch) || ch == '\t');
}

void print_str(const char *str) {
  printf("[");
  while (*str != '\0') {
    printf("%c", *(str++));
  }
  printf("]\n");
}