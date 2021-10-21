#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* Angiver prototyper til funktionerne så compileren ved at de findes.*/
void solveQuadraticEquation(double a, double b, double c);
double calcDiscriminant(double a, double b, double c);
void twoRoots(double a, double b, double disc);
double oneRoot(double a, double b);
/* 
I min main spørger jeg brugeren om en a, b og c værdi på en andengradsligning.
Så har jeg et sentinel controlled loop som gør at programmet spørger igen om input efter den har regnet den forrige andengradsligning ud.
Hvis brugeren angiver a til 0 stoppes programmet fordi at hvis a er lig 0 er det ikke længere en andengrads ligning!
*/
int main(void) {
  double a, b, c;
  
  printf("Angiv henholdsvis a, b og c værdien i en andengradsligning af formen a * x^2 + b * x + c = 0: ");
  scanf(" %lf %lf %lf", &a, &b, &c);

  while ((a != 0)){
    solveQuadraticEquation(a, b, c);
    printf("Angiv henholdsvis a, b og c værdien i en andengradsligning af formen a * x^2 + b * x + c = 0: ");
    scanf(" %lf %lf %lf", &a, &b, &c);
  }
  return EXIT_SUCCESS;
}

/* Funktionen solveQuadraticEquation tjekker alt efter resultaten af diskriminanten om der er 2, 1 eller ingen mulige løsninger */
void solveQuadraticEquation(double a, double b, double c){
  double discriminant = calcDiscriminant(a, b, c);
  
  if (discriminant > 0.0)
    twoRoots(a, b, calcDiscriminant(a, b, c));
  else if (discriminant == 0.0)
    printf("Der findes en løsning som er x = %4.3f.\n\n", oneRoot(a, b));
  else
    printf("Der er ingen løsning, da diskriminanten er mindre end 0.\n\n");
  return;
}

/* Funktionen clacDiscriminant regner diskriminanten ud. Den tager 3 parametre som alle er doubles, og retunerer værdien af diskriminanten. */
double calcDiscriminant(double a, double b, double c)
  return pow(b,2) - 4 * a * c;

/* Funktionen twoRoots finder 2 mulige løsninger til x og printer svarene ud i terminalen */
void twoRoots(double a, double b, double disc) {
  double x1, x2;

  x1 = (-b + sqrt(disc)) / (2 * a);
  x2 = (-b - sqrt(disc)) / (2 * a);

  printf("Der findes to løsninger som er x = %4.3f og x = %4.3f.\n\n", x1, x2);
  return;
}

/* Funktionen oneRoot finder løsningen til x når der kun er 1. */
double oneRoot(double a, double b)  
  return (-b) / (2 * a);
