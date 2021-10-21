#include <stdio.h>

long fib(long n);
int main(){
  long i;

  for(i = 0; i < 100; i++)
    printf("Fib(%li) = %li\n", i, fib(i));
  
  return 0;
}

long fib(long n){     /* working program: fib-memo.c - an exercise*/
  long result;

  static long mem1 = 0;
  static long mem2 = 0;

  if (n == 0)
    result = 0;
  else if (n == 1)
    result = 1;
  else if (mem2)
    result = mem1 + mem2;
  mem2 = mem1;
  mem1 = result;

  return result;
}