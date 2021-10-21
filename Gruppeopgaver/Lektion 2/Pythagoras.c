#include <stdio.h>

int main(void){

  int m, n, side1, side2, hypotenuse;
  
  printf("Enter two integers, the first number should be larger than the second: ");
  scanf(" %d%d", &m, &n);

  side1 = (m * m) - (n * n);
  side2 = 2 * m * n;
  hypotenuse = (m * m) + (n * n);

  printf("side1 = %d\nside2 = %d\nhypotenuse = %d\n", side1, side2, hypotenuse);

  return(0);
}