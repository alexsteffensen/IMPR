#include <stdio.h>
#include <stdlib.h>

int main(void){

  int pH;
  
  printf("Enter a pH value: ");
  scanf(" %d", pH);

  if(pH > 7){
    if(pH < 12)
      printf("Akaline");
    else
      printf("Very alkaline");
  }
  else {
    if(pH == 7)
      printf("Neutral");
    else {
      if(pH > 2)
        printf("Acidic");
      else
        printf("Very acidic");   
    }
  }
  return EXIT_SUCCESS;
}

//I forhold til opgave 3.3, så giver det samme resultat. If-else kæden er kommenteret ud nedenunder. Man får samme svar på grund af de expressions den laver
/*
  if (ph <= 2)
     printf("Very acidic");  
  else if (ph < 7) 
     printf("Acidic");       
  else if (ph == 7)
     printf("Neutral");      
  else if (ph < 12)
     printf("Alkaline");     
  else 
     printf("Very alkaline");

*/