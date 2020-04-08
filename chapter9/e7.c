// Chapter 9 - exercise 7
#include <ctype.h>
#include <stdio.h>

int alphabet_position(char);

int main(void) {

  char ch;

  printf("character: ");
  while ((scanf("%c", &ch) == 1) && ch != EOF) {
    if (ch == '\n') {
      continue;
    }
    if (!isalpha(ch)) {
      printf("it's not a letter!\n");
      continue;
    }
    printf("alphabet: %d\n", alphabet_position(ch));
    printf("character: ");
  }

  return 0;
}

int alphabet_position(char ch) { return (tolower(ch) - 'a' + 1); };
