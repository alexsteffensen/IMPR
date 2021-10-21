#include <stdio.h>

#define SEK_PR_MIN 60 // Definerer hvor mange sekunder der går pr. minut.
#define SEK_PR_TIME 60 * SEK_PR_MIN // Definerer hvor mange sekunder der går på en time.
#define SEK_PR_DAG 24 * SEK_PR_TIME // Definerer hvor mange sekunder er går på en dag.
#define SEK_PR_UGE 7 * SEK_PR_DAG // Definerer hvor mange sekunder på en uge.

int main(void){

  int input, uger, dage, timer, min, sek; // Opretter variablerne uden at tildele dem en værdi.

  printf("Indtast et helt antal sekunder: "); // Siger til brugeren at der skal indtastes et antal helt antal sekunder.
  scanf(" %d", &input); // Det antal sekunder som brugeren skriver ind tildeles til input.

  uger = input / (SEK_PR_UGE); // Regner ud hvor mange uger der er i det antal sekunder som brugeren har indtaset og resultatet tilskrives til variablen "uger".
  input = input % (SEK_PR_UGE); // Regner det resterende antal sekunder ud som brugeren har skrevet.

  dage = input / (SEK_PR_DAG); // Regner ud hvor mange dage der er i det resterende antal sekunder som brugeren har indtastet efter uger, og resultatet tilskrives til variablen "dage".
  input = input % (SEK_PR_DAG); // Regner det resterende antal sekunder ud som brugeren har skrevet.

  timer = input / (SEK_PR_TIME); // Regner ud hvor mange timer der er i det resterende antal sekunder som brugeren har indtastet efter uger og timer og resultatet tilskrives til variablen "timer".
  input = input % (SEK_PR_TIME); // Regner det resterende antal sekunder ud som brugeren har skrevet.

  min = input / (SEK_PR_MIN); // Regner ud hvor mange minutter der er i det resterende antal sekunder efter jeg har regnet uger, dage og timer ud, og resultatet tilskrives til variablen "min".
  sek = input % (SEK_PR_MIN); // Regner det resterende antal sekunder ud som brugeren har og det tilskrives til variablen "sek".

  printf("Dit antal indtastede sekunder er %d uger, %d dage, %d timer, %d minutter og %d sekunder.", uger, dage, timer, min, sek); // Udskriver tekst med det antal uger, dage, timer, minutter og sekunder som de antal sekunder brugeren indtastede er.

  return(0); // Nulstiller værdierne på variablerne indeni funktionen.
}