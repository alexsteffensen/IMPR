#include "opg5.2.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int counter,
      a = 1,
      prime_number = 1;

  printf("How many prime numbers would you like to be printed? ");
  scanf(" %d", &counter);

  while(counter > 0) {
    if (is_prime(a)){
      printf("prime %d : %d\n", prime_number, a);
      prime_number++;
      counter--;
    }
    a++;
  }
  return EXIT_SUCCESS;
}
