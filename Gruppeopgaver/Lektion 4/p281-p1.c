#include <stdio.h>
#include <stdlib.h>

int main (void) {
    
  int people = 9870, year = 0;

  for (int i = 0; i <= 30; i++){
    people *= 1.10;
    year += 1;
    printf("I år %d var befolkningen %d\n", year, people);
    if (people >= 30000){
      printf("Det tog %d år for byen at nå 30000 indbyggere.\n", year);
      break;
    }
  }

  return EXIT_SUCCESS;
}