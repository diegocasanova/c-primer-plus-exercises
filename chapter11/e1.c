// Chapter 11 - exercise 1
/* Design and test a function that fetches the next n characters from input
 * (including blanks, tabs, and newlines), storing the results in an array whose
 * address is passed as an argument.
 */

#include <stdio.h>
#include <string.h>

#define STR_SIZE 10

unsigned long read_str(char *str, int size);

int main(void) {

  char str[STR_SIZE];

  while ((read_str(str, STR_SIZE)) != 0) {
    puts("line:");
    puts(str);
  }

  puts("Bye!");
  return 0;
}

unsigned long read_str(char *str, int size) {
  char ch;
  int i = 0;
  while ((ch = getchar()) != EOF && i < (size - 1)) {
    str[i] = ch;
    i++;
  }
  str[i] = '\0';
  return strlen(str);
}
