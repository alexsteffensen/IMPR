/*
Alexander Skytt Steffensen
asteff20@student.aau.dk
Gruppe: A408b
Studieretning: Software
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Prototyperne til funktioneren */  
double run_calculator();
void scan_data(double *, char *);
void do_next_op(double, char, double, double *);
int check_operator(char);
double unary_operator(double, char);
double sq_root(double);
double div_by_one(double);
double binary_operator(double, char, double);
double divide(double, double);

/* I min main kører jeg funktionen run_calculator() og printer det endelige resultat. */
int main(void){
  printf("Final result is: %4.3f\n", run_calculator());
  return EXIT_SUCCESS;
}


/* I run_calculator funktionen køres dialogen med brugeren. Der kører et sentinel controlled loop. 
   I loopet beregnes operationen som scannes i scan_data, hvis det ikke er 'q' og udskriver resultatet.
   Til sidst i funktionen returneres akkumulatorens endelige værdi. */
double run_calculator(){
  double accumulator = 0.0,
         operand;
  char operator = '+';

  while(operator != 'q') {
    printf("Enter operator, and an optional operand: ");
    scan_data(&operand, &operator);
    
    if (operator != 'q'){
      do_next_op(operand, operator, accumulator, &accumulator);
      printf("Result so far is %4.3f.\n", accumulator);
    }
  }  

  return accumulator;
}


/* I funktionen scan_data tages operanden og operatoren som output parametre.
  Der scannes der for en operator, Hvis en binær operator scannes bliver der 
  også scannet for en operand, ellers sættes operanden til 0.0 */
void scan_data(double *poperand, char *poperator){
  scanf(" %c", poperator);

  if (*poperator == '+' || *poperator == '-' || *poperator == '*' || *poperator == '/' || *poperator == '^')
    scanf(" %lf", poperand);
  else if (*poperator == '#' || *poperator == '%' || *poperator == '!')
    *poperand = 0.0;
}


/* I funktionen do_next_op tages operanden, operatoren og akkumulatoren som input parametre. 
  Akkumulatoren tages også som out parameter (som en pointer).
  Her i funktionen tjekkes der om der skal køres en unær eller binør operation */
void do_next_op(double operand, char operator, double accumulator, double *paccumulator){
  if (check_operator(operator) == 1)
    *paccumulator = binary_operator(accumulator, operator, operand);
  else if (check_operator(operator) == 0)
    *paccumulator = unary_operator(accumulator, operator);
}


/* I funktionen check_operator tages operatoren som input parameter som køres i en switch, 
   som tjekker hvilken operator vi har at gøre med */
int check_operator(char operator) {
  switch (operator) {
    case '+' : case '-' : case '*' : case '/' : case '^' :
      return 1;

    case '#' : case '%' : case '!' :
      return 0;

    default:
      return -1;
  }
}


/* I funktionen unary_operator tages akkumulatoren og operatoren ind som en input parameter.
   der bruges et switch statement til at finde ud af hvilken operator der bruges, for derefter
   at returnere den beregnede værdi. */
double unary_operator(double accumulator, char operator){
  switch (operator){
    case '#' : return sq_root(accumulator);
    case '%' : return accumulator * -1;
    case '!' : return div_by_one(accumulator);
    default  : return accumulator;
  }
}

/* sq_root tager accumulatoren som parameter input og tager kvadratroden af den hvis den ikke er negativ.
   Ellers ignoreres operationen */
double sq_root(double accumulator) {
  if (accumulator >= 0)
    return sqrt(accumulator);
  else
    return accumulator;
}

/* div_by_one tager accumulatoren som parameter input og returnerer den resiprokke værdi af den hvis akkumulatoren ikke er 0.
   Ellers ignoreres operationen */
double div_by_one(double accumulator) {
  if (accumulator == 0)
    return accumulator;
  else 
    return 1/accumulator;
}


/* I funktionen binary_operator tages akkumulatoren, operatoren og operanden som input parameter,
   et switch statement bruges til at finde hviklen binær operator der bruges, for derefter
   at udføre beregningen og returnere den som en double. */
double binary_operator(double accumulator, char operator, double operand){
  switch (operator){
    case '+' : return accumulator + operand;
    case '-' : return accumulator - operand;
    case '*' : return accumulator * operand;
    case '^' : return pow(accumulator, operand);
    case '/' : return divide(accumulator, operand);
    default  : return accumulator;
  }
}

/* div_by_one tager accumulatoren og operanden som parameter input og returnerer akkumulatoren / operanden hvis operanden er forskellig fra 0.
   Ellers ignoreres operationen */
double divide(double accumulator, double operand) {
  if (operand != 0)
    return accumulator / operand;
  else 
    return accumulator;
}


