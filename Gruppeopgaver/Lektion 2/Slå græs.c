#include <stdio.h>

#define FT2_PR_M2 21.52
#define GRAES_PR_SEK 1

int main(void){

  int grundAreal, husAreal, grundLaengde, grundBredde, husBredde, husLaengde, tid, min, sek,
  sekPrMin = 60;
  double graesplaene;

  printf("Skriv længden og bredden af grunden i m (heltal): ");
  scanf(" %d %d", &grundLaengde, &grundBredde);
  printf("Skriv længden og bredden af huset i m (heltal): ");
  scanf(" %d %d", &husLaengde, &husBredde);

  grundAreal = grundLaengde * grundBredde;
  husAreal = husLaengde * husBredde;

  graesplaene = grundAreal - husAreal;
  tid = (graesplaene * FT2_PR_M2) * GRAES_PR_SEK;

  min = tid / sekPrMin;
  sek = tid % sekPrMin;

  printf("Arealet af de 3 dele er følgende: \nHus: %d\nGrund: %d\nGræsplænen: %4.2f\n", husAreal, grundAreal, graesplaene);
  printf("Det tager %d minutter og %d sekunder at slå græsplænen\n", min, sek);

  return(0);
}