#include <stdio.h>
#include <stdlib.h>

int main(void){

  int a, b, largest, smallest, divisor, i;

  /* Brugeren skal indtaste 2 positive heltal */
  printf("Indtast to positive heltal: ");
  scanf(" %d %d", &a, &b);
  
  /* Finder ud af om et negativt tal er intastet*/
  while (a > 0 && b > 0){

    /* Finder det mindste og største tal gennem betingede udtryk */
    smallest = (a >= b) ? b : a;
    largest = (a >= b) ? a : b;
  
    /* Kører et for loop som kører igennem alle tal fra "largest" til 0. 
    Den går oppe fra og ned fordi så når den bare finder det første 
    kan jeg break ud af loopet. */
    for (i = largest; i >= 0; --i) {

      if (smallest % i == 0 && largest % i == 0){
        divisor = i;
        printf("Den største fælles divisor af %d og %d er %d\n", smallest, largest, divisor);
        break;
      }
    }

    /*Spørger ind til print igen */
    printf("Indtast to positive heltal: ");
    scanf(" %d %d", &a, &b);
  }

  return EXIT_SUCCESS;
}
