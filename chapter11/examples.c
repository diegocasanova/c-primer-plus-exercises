// Chapter 11 - Examples
#include <stdio.h>
#include <string.h>

#define STR_LEN 10
#define WORLD "world"

int main(void) {

  char str[STR_LEN];
  char hello[20] = "Hello, ";
  unsigned long str_len;
  char no_str[] = {'A', 'B', 'C'};

  fputs("Testing fputs()\n", stdout);

  while ((fgets(str, STR_LEN, stdin)) && str[0] != '\n') {
    fputs(str, stdout);
  }

  str_len = strlen(str);

  printf("\nstring length [%ld]\n", str_len);
  if (str_len == 1) {
    printf("str = [%d]\n", str[0]);
  }
  puts(str);
  puts(no_str);

  strncat(hello, WORLD, 20);
  puts(hello);

  puts("Bye!");

  return 0;
}