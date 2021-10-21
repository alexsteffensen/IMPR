#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Prototyper */
double trap(double a, double b, double n, double f(double x));
double sum_part(double a, double b, double h, double f(double x));
double half_circle(double x);
double sinus_func(double x);

/* i main køres et loop for n så arealet beregnes 
   når n er 2, 4, 8, 16, 32, 64 og 128 og printes*/
int main(void) {
  double a = -2.0,
         b = 2.0,
         n;

  for (n = 2.0; n <= 128.0; n *= 2.0) {
    printf("n = %.2f areal = %.2f \n", n, trap(a, b, n, half_circle));
  }

  return EXIT_SUCCESS;
}

/* i trap funktionen beregnes arealet, 
   ved brug af formlen angivet i opgaven */
double trap(double a, double b, double n, double f(double)) {
  double h = (b - a) / n;
  
  return h/2 * (f(a) + f(b) + 2 * sum_part(a, b, h, f));
}

/* sum_part beregner sum delen af udregningen, så programmet forfines*/
double sum_part(double a, double b, double h, double f(double)) {
  double sum = 0.0,
         i;

  for (i = a + h; i < b; i += h) {
    sum += f(i);
  }
  return sum;
}

/* half_circle tager en x-værdi og returnerer 
 y-værdien for en halvcirkel graf med en radius på 2*/
double half_circle(double x) {
  return sqrt(4 - pow(x, 2));
}

double sinus_func(double x) {
  return pow(x, 2) * sin(x);
}
