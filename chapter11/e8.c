// Chapter 11 - exercise 8
/* Write a function called string_in() that takes two string pointers as
arguments. If the second string is contained in the first string, have the
function return the address at which the contained string begins. For instance,
string_in("hats", "at") would return the address of the a in hats. Otherwise,
have the function return the null pointer. Test the function in a complete
program that uses a loop to provide input values for feeding to the function.
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define STR_SIZE 50

char *read_str(char *str, unsigned int size);
bool is_break_line(char ch);
char *string_in(const char *str, const char *sub_str);

int main(void) {

  char str[STR_SIZE];
  char sub_str[STR_SIZE];
  char *found;

  while (read_str(str, STR_SIZE)) {
    printf("substring ");
    if (!read_str(sub_str, STR_SIZE)) {
      puts("Failed to read substring!");
      return 1;
    }

    if ((found = string_in(str, sub_str)) != NULL) {
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

bool is_break_line(char ch) { return (ch == EOF || ch == '\n'); }

char *string_in(const char *str, const char *sub_str) {
  return strstr(str, sub_str);
}