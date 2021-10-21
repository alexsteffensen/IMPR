#include <stdio.h>

int quotient(int dividend, int divisor);
int modulus(int dividend, int divisor);

int main(void){
  printf("%d\n", quotient(25, 7));
  printf("%d\n", modulus(24, 7));
  return 0;
}

int quotient(int dividend, int divisor){
  if(dividend - divisor >= 0)
    return 1 + quotient(dividend - divisor, divisor);
  else
    return 0;
}

int modulus(int dividend, int divisor){
  if(dividend - divisor >= 0)
    return modulus(dividend - divisor, divisor);
  else
    return dividend;
}

