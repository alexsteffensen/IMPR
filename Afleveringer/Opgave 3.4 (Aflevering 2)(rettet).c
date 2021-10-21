#include <stdio.h>
#include <stdlib.h>

#define SEK_PR_MIN 60
#define SEK_PR_TIME 60 * SEK_PR_MIN

int main(void){
  
  // De forskellige variabler 
  int input, timer, min, sek;

  //Spørger om input fra brugeren, og modtager input som tilskreves "input" variablen
  printf("Indtast et helt antal sekunder: ");
  scanf(" %d", &input);

  // Antal timer, minutter og sekunder regnes ud.  
  timer = input / (SEK_PR_TIME);
  input = input % (SEK_PR_TIME);

  min = input / (SEK_PR_MIN);
  sek = input % (SEK_PR_MIN);

  printf("Det antal indstatede sekunder er");

  //Finder ud af hvad der skal printes for time(r) og minut(ter) med if-else sætninger. Jeg finder ud af hvad der skal printes for sekund(er) med betingede udtryk.
  if (timer > 1)
    printf(" %d timer", timer);
  else if (timer == 1)
    printf(" %d time", timer);

  if (timer > 0 && min > 0 && sek > 0)
    printf(",");

  if (min > 1)
    printf("%s %d minutter", (timer > 0 && min > 0 && sek > 0) ? "" : " og", min);
  else if (min == 1) 
    printf("%s %d minut", (timer > 0 && min > 0 && sek > 0) ? "" : " og", min);

  if (sek == 0) 
    printf(".\n");
  else
    printf("%s %d %s.\n", (min > 0 || timer > 0) ? " og" : "", sek, (sek == 1) ? "sekund" : "sekunder");

  return EXIT_SUCCESS;

}