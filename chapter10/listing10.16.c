// Chapter 10 - listing 10.16
#include <stdio.h>

#define COLS 2
#define ROWS 4

int main(void) {

  int zippo[ROWS][COLS] = {{2, 3}, {6, 8}, {1, 3}, {5, 7}};
  int(*pz)[2];

  pz = zippo;

  printf(" pz = %p, pz + 1 = %p\n", pz, pz + 1);
  printf("pz[0] = %p, pz[0] + 1 = %p\n", pz[0], pz[0] + 1);
  printf("*pz = %p, *pz + 1 = %p\n", *pz, *pz + 1);
  printf("pz[0][0] = %d\n", pz[0][0]);
  printf(" *pz[0] = %d\n", *pz[0]);
  printf(" **pz = %d\n", **pz);
  printf(" pz[2][1] = %d\n", pz[2][1]);
  printf("*(*(pz+2) + 1) = %d\n", *(*(pz + 2) + 1));

  return 0;
}