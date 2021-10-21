#include <stdio.h>

int main(void) {

  int watt, lumen;

  printf("Indtast antal watt: ");
  scanf(" %d", &watt);

  switch(watt) {
      case 15:  lumen = 125;  break;
      case 25:  lumen = 215;  break;
      case 40:  lumen = 500;  break;
      case 60:  lumen = 880;  break;
      case 75:  lumen = 1000; break;
      case 100: lumen = 1675; break;
      default:  lumen = -1;   break;
  }

  if (lumen == -1) {
      printf("Du har indtastet et ugyldigt antal watt!\n");
  }
  else {
      printf("Det antal watt svarer til en lysstyrke på %d lumen\n", lumen);
  }

  return(0);
}