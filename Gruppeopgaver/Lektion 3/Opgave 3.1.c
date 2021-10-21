#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define DELTA 0.1

int main(void){

double r, x, y, xylaengde;

printf("Angiv en radius til en cirkel: ");
scanf(" %lf", &r);

printf("Angiv en x og en y værdi til et punkt på et koordinatsystem: ");
scanf(" %lf %lf", &x, &y);

xylaengde = sqrt(pow(x,2) + pow(y,2));

printf("Punktet %s cirkel periferien.\n", (xylaengde > (r + DELTA) || xylaengde < (r - DELTA)) ? "ligger udenfor" : (xylaengde == r) ? "ligger på" : "ligger med en afstand på 0.1 eller mindre fra");

return EXIT_SUCCESS;

}