// Chapter 11 - exercise 13
/* Write a program that echoes the command-line arguments in reverse word order.
 * That is, if the command-line arguments are see you later, the program should
 * print later you see.
 */

#include <stdio.h>

int main(int argc, char *argv[]) {

  if (argc > 1) {
    for (int i = argc - 1; i > 0; i--) {
      printf("%s ", argv[i]);
    }
    printf("\n");
  }

  return 0;
}
