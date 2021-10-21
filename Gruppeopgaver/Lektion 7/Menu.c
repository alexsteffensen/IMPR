#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum starters {guacamole, tarteletter, lakserulle, græskarsuppe};
enum main_courses {gyldenkål, hakkebøf, gullash, forloren_hare};
enum desserts {pandekager_med_is, gulerodskage, chokolademousse, citronfromage};

void maaltid();

int main(void) {

  srand(time(NULL));

  for (int i = 1; i <= 25; i++) {
    maaltid();
  }
  return EXIT_SUCCESS;
}

void maaltid() {
  enum starters starter = rand() % 4;
  enum main_courses main_course = rand() % 4;
  enum desserts dessert = rand() % 4;

  printf("Forret: %s\nHovedret: %s\nDessert:%s.\n", 
         (starter == 0) ? "guacamole" : (starter == 1) ? "tarteletter" : (starter == 2) ? "lakserulle" : "græskarsuppe",
         (main_course == 0) ? "gyldenkål" : (main_course == 1) ? "hakkebøf" : (main_course == 2) ? "gullash" : "forloren hare",
         (dessert == 0) ? "pandekager_med_is" : (dessert == 1) ? "gulderodskage" : (dessert == 2) ? "chokolademousse" : "citronfromage"
        );
 }

