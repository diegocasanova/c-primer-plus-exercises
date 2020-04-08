// Chapter 11 - exercise 7
/* The strncpy(s1,s2,n) function copies exactly n characters from s2 to s1,
 * truncating s2 or padding it with extra null characters as necessary. The
 * target string may not be null-terminated if the length of s2 is n or more.
 * The function returns s1. Write your own version of this function; call it
 * mystrncpy(). Test the function in a complete program that uses a loop to
 * provide input values for feeding to the function.
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define SRC_SIZE 50
#define DEST_SIZE 11

char *read_str(char *str, unsigned int size);
bool is_break_line(char ch);
char *my_strncpy(char *destination, const char *source, unsigned int size);

int main(void) {

  char str[SRC_SIZE];
  char destination[DEST_SIZE];

  while (read_str(str, SRC_SIZE)) {
    if (my_strncpy(destination, str, DEST_SIZE)) {
      printf("copied: %s\n", destination);
      printf("length: %lu\n", strlen(destination));
      getchar();
    } else {
      puts("Error while copying strings!");
    }
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

char *my_strncpy(char *destination, const char *source, unsigned int size) {
  if (strlen(source) < size) {
    return strncpy(destination, source, size);
  } else {
    destination[size - 1] = '\0';
    return strncpy(destination, source, size - 1);
  }
}
