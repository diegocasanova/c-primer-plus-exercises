// Chapter 4 - exercise 5 - basic IO
#include <stdio.h>

int main(void) {

  float down_speed, file_size;
  const int UNITS = 1024;
  const int BITS_PER_BYTES = 8;

  printf("Download speed (Mbs): ");
  scanf("%f", &down_speed);
  printf("File size (MB): ");
  scanf("%f", &file_size);

  float file_size_bits = (file_size * UNITS * UNITS * BITS_PER_BYTES);
  float time = file_size_bits / (down_speed * 1000000);

  printf("At %.2f megabits per second, a file of %.2f megabytes\n", down_speed,
         file_size);
  printf("downloads in %.2f seconds.\n", time);

  return 0;
}