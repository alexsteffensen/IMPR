#include <stdio.h>

int main(void) {
  
  int i = 3, j = 4, k = 5; //Der laves 3 int variabler som har henholdsvis værdien  3, 4 og 5.
  int res1, res2, res3;  //Der laves endnu 3 int variabler dog uden værdier
  
  i++; j--; ++k; //i tælles op med 1 og bliver tilskrevet 4, j tælles ned med 1 og bliver tilskrevet 3 og k tælles op med 1 og får tilskrevet 6

  printf("i: %d, j: %d, k: %d\n", i,j,k); //De nye værdier for i, j og k bliver printet ud i terminalen

  res1 = --i; // i bliver talt ned inden at værdien bliver tilskrevet res1. Så res1 = 3.
  res2 = j++; // j bliver talt op efter at js værdi bliver tilskrevet til res2. Så res2 = 3.
  res3 = --k; // k bliver talt ned inden at værdien bliver tilskrevet res3. Så res3 = 6.

  printf("res1: %d, res2: %d, res3: %d\n", res1, res2, res3); // res1, res2 og res3s værdier bliver printet ud i terminalen.
  printf("i: %d, j: %d, k: %d\n", i,j,k); // i, j og ks værdier bliver printet ud i terminalen.
  
  return 0; // vi returnerer 0 for at få kontrollen tilbage i operativsystemet.
}