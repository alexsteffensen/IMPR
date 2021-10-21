#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int age, year, speed, y, x, z, w;
  double water;

  if(age >= 18 && age <= 21) 
    printf("Age is between 18 and 21, or 18 and 21.");
  if(water < 1.5 && water > 0.1)
    printf("Water is greater than 0.1, and less than 1,5.");
  if(year % 4 == 0)
    printf("year is divisible by 4.");
  if(speed < 55)
    printf("The speed is less than 55");
  if(y < z && y > x)
    printf("y is less than z, but greater than x");
  if(w == 6 || w >= 3)
    printf("w is either equal to 6 or not less than 3");

  return EXIT_SUCCESS;
}