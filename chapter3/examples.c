#include <inttypes.h>
#include <stdio.h>

int main(void) {
  int32_t me32; // me32 a 32-bit signed variable
  me32 = 45933945;
  printf("First, assume int32_t is int: ");
  printf("me32 = %d\n", me32);
  printf("Next, let's not make any assumptions.\n");
  printf("Instead, use a \"macro\" from inttypes.h: ");
  printf("me32 = %" PRId32 "\n", me32);
  printf("sizeof(int) = %lu bytes\n", sizeof(int));

  printf("Type int has a size of %zd bytes.\n", sizeof(int));
  printf("Type char has a size of %zd bytes.\n", sizeof(char));
  printf("Type long has a size of %zd bytes.\n", sizeof(long));
  printf("Type long long has a size of %zd bytes.\n", sizeof(long long));
  printf("Type double has a size of %zd bytes.\n", sizeof(double));
  printf("Type long double has a size of %zd bytes.\n", sizeof(long double));

  return 0;
}
