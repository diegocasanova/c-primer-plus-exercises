// Chapter - examples
#include <stdio.h>
#include <string.h>

#define Q "\"His Hamlet was funny without being vulgar.\""

int main(void) {
  int number;
  printf("number: ");
  scanf("%d", &number);
  printf("entered: %d\n", number);

  char name[40];
  printf("name: ");
  scanf("%s", name);
  printf("entered: %s\n", name);

  printf("He sold the painting for $%2.2f.\n", 2.345e2);
  printf("Is %2.2e the same as %2.2f?\n", 1201.0, 1201.0);
  printf("%c%c%c\n", 'H', 105, '\41');

  printf("%s\nhas %zd characters.\n", Q, strlen(Q));
}