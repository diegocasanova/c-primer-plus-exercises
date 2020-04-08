// Chapter 12 - exercise 9
/* Write a program with the following behavior. First, it asks you how many
 * words you wish to enter. Then it has you enter the words, and then it
 * displays the words. Use malloc() and the answer to the first question (the
 * number of words) to create a dynamic array of the corresponding number of
 * pointers-to-char. (Note that because each element in the array is a
 * pointer-to-char, the pointer used to store the return value of malloc()
 * should be a pointer-to-a-pointer-to-char.) When reading the string, the
 * program should read the word into a temporary array of char, use malloc() to
 * allocate enough storage to hold the word, and store the address in the array
 * of char pointers. Then it should copy the word from the temporary array into
 * the allocated storage. Thus, you wind up with an array of character pointers,
 * each pointing to an object of the precise size needed to store the particular
 * word
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_MAX_SIZE 50

void print_words(char **words, int n_words);
void free_words(char **words, int n_words);

int main(void) {

  char **words;
  int n_words;

  printf("How many words do you wish to enter?");
  scanf("%d", &n_words);

  if (n_words < 1) {
    printf("number of words should be >= 1");
    return EXIT_FAILURE;
  }

  words = (char **)malloc(n_words * sizeof(char *));
  printf("Enter %d words now:\n", n_words);
  for (int i = 0; i < n_words; i++) {
    char str[STR_MAX_SIZE];
    scanf("%s", str);
    words[i] = (char *)malloc(strlen(str) * sizeof(char));
    strncpy(words[i], str, strlen(str));
  }

  print_words(words, n_words);
  free_words(words, n_words);

  return EXIT_SUCCESS;
}

void print_words(char **words, int n_words) {
  printf("Here are your words:\n");
  for (int i = 0; i < n_words; i++) {
    printf("%s\n", words[i]);
  }
}

void free_words(char **words, int n_words) {
  for (int i = 0; i < n_words; i++) {
    free(words[i]);
  }
  free(words);
}