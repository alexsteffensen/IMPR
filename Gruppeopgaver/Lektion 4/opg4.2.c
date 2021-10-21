#include <stdio.h>
#include <stdlib.h>

int main (void) {

  int m, n, k, sum = 0;

  printf("indtast 3 tal, det sidste tal skal være større end 1, og det første tal skal være større end det andet tal: ");
  scanf(" %d %d %d", &m, &n, &k);

  for (int i = m; i < n; i++){
    if (i % k == 0 || k % i == 0)
      sum += i;
  }

  printf("Summen er %d\n", sum);

  return EXIT_SUCCESS;

}