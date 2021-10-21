#include <stdio.h>
#include <stdlib.h>

void conversion(double dollars, double *pyen, double *prubler, double *pcrowns, double *peuros);

int main(void) {
  double dollars, yen, rubler, crowns, euros;

  printf("Type an amount of dollars: ");
  scanf(" %lf", &dollars);

  conversion(dollars, &yen, &rubler, &crowns, &euros);

  printf(" %f yen, %f rubler, %f crowns, %f euros.\n", yen, rubler, crowns, euros);

  return EXIT_SUCCESS;
}

void conversion(double dollars, double *yen, double *rubler, double *crowns, double *euros) {
  *yen = dollars * 119.9;
  *rubler = dollars * 66.43;
  *crowns = dollars * 6.66;
  *euros = dollars * 0.89;
}
