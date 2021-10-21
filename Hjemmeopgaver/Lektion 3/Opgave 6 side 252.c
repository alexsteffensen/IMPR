#include <stdio.h>

int main(void){

  int x, y;
  
  printf("Angiv en x koordinat: ");
  scanf(" %d", &x);
  printf("Angiv en y koordinat: ");
  scanf(" %d", &y);

  if(x > 0) {
      if(y > 0) 
        printf("Dit angivede koordinat ligger i 1. kvadrant.\n");
      else 
        printf("Dit angivede koordinat ligger i 4. kvadrant.\n");
  }
  else {
      if(y > 0) 
        printf("Dit angivede koordinat ligger i 2. kvadrant.\n");
      else 
        printf("Dit angivede koordinat ligger i 3. kvadrant.\n");
  }

  return(0);


}