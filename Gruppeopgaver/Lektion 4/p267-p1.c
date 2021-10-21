#include<stdio.h>
/*1 + 2 + 3 + ... + (n - 1) + n*/
/* (n * (n + 1)) / 2 */

int main (){
  int n, sum = 0, check;
  scanf(" %d", &n);

  for (int i = 1; i <= n; i++)
    sum += i;

  check = (n * (n + 1)) / 2;

  printf("%s\n", sum == check ? "True" : "False");

  return 0;
}
