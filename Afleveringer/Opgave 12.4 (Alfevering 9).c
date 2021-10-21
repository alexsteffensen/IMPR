#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_CARDS 55
#define NUM_OF_JOKERS 3

enum suits {clubs, diamonds, hearts, spades};
enum values {two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};

typedef enum suits suit;
typedef enum values value;

/* min struct af et kort. is_joker er en boolsk værdi alt efter om det er en joker eller ej. */
struct card {
  int suit;
  int value;
  int is_joker;
};

typedef struct card card;

void print_card(card c, int cardnum);
void sort_cards(card *cardset);
int comp_cards(const void* a, const void* b);

/* I main laves arrayet til kortene og kortene lægges over i en forkert rækkefølge med vilje
 så man kan se at sorteringsfunktionen virker. Se enumerationsene for hvilken */
int main(void) {
  int i, j;
  int cardnum = 0;
  card cardset[NUM_OF_CARDS];
  
  /* Kortene lægges ind i en forkert rækkefølge med vijle! */
  for (i = 0; i < NUM_OF_JOKERS; i++) {
    cardset[cardnum].is_joker = 1;
    cardnum++;
  }

  for (i = spades; i >= clubs; i--) {  
    for (j = ace; j >= two; j--) {
      cardset[cardnum].suit = i;
      cardset[cardnum].value = j;
      cardset[cardnum].is_joker = 0;
      cardnum++;
    }
  }
  
  /* Før sortering */
  for (i = 0; i < NUM_OF_CARDS; i++)
    print_card(cardset[i], i+1);
  
  sort_cards(cardset);

  printf("*CARDS SORTING*\n\n");

  /* Efter sortering */
  for (i = 0; i < NUM_OF_CARDS; i++)
    print_card(cardset[i], i+1);

  return EXIT_SUCCESS;
}

void print_card(card c, int cardnum) {
  int joker;
  char *suit_name[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
  char *value_name[13] = {"Two", "Three", "Four", "Five", "Six", "Seven",
                          "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
  joker = c.is_joker;
  
  if (joker){
    printf("Cardnumber: %d\n JOKER! \n\n", cardnum);
  }
  
  else {
    printf("Cardnumber: %d\n"
           "Suit: %s\n"
           "Value: %s\n\n",
           cardnum, suit_name[c.suit], value_name[c.value]);
  }
}

/* Funktionen der sorterer kortene ved brug af qsort() */
void sort_cards(card *cardset) {
  qsort(cardset, NUM_OF_CARDS, sizeof(card), comp_cards);
}

/* Funktionen under sammenligner kortene, så at jokerne ryger i bunden og derefter prioriteres efter kulør og til sidst efter værdi */
int comp_cards(const void* a, const void* b) {
  int is_joker1 = ((card*)a)->is_joker,
      is_joker2 = ((card*)b)->is_joker;
  int suit1 = ((card*)a)->suit,
      suit2 = ((card*)b)->suit;
  int value1 = ((card*)a)->value,
      value2 = ((card*)b)->value;
  
  if (is_joker1 == is_joker2) {
    if (suit1 == suit2)
      return value1 - value2;
    else 
      return suit1 - suit2;
  }
  else
    return is_joker1 - is_joker2;
}



