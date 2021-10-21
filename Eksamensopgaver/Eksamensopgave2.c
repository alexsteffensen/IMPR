/*
Navn: Alexander Skytt Steffensen
E-mail: asteff20@student.aau.dk
Gruppe: A408b
Studieretning: Software
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define DIE_MAX_EYES 6
#define DIE_MIN_EYES 1

void roll_multiple_dice(int dice[], int N);
void run_yatzy(void);
int upper_check(int dice[], int N, int check);
int check_bonus(int upper_result);
int identical_values(int dice[], int N, int max, int qty);
int check_two_pair(int dice[], int N, int pair);
int straight(int dice[], int N, int start, int end);
int check_full_house(int dice[], int N, int pair);
int check_chance(int dice[], int N);
int check_yatzy(int dice[], int N);

/* I main initialiseres random generatoren til computerens ur og funktionen run_yatzy køres. */
int main(void) {
  srand(time(NULL));
  run_yatzy();
  return EXIT_SUCCESS;
}

/*
run_yatzy er funktionen hvor  der køres dialogen og udprint til terminalen.
Gennem et loop køres yatzy programmet hvor der allokeres lager med malloc, 
terningerne rystes, kalder funktionerne i de forskellige combinationer.
Til sidst tilbydes brugeren endnu et spil.
*/
void run_yatzy(void) {
  int N = 0,
      j, i,
      result,
      section_score = 0,
      pair = 2;
  int *dice;
  enum combs {ones = 1, twos, threes, fours, fives, sixes, bonus, one_pair, two_pairs, three_of_kind, 
              four_of_kind, small_straight, long_straight, full_house, chance, yatzy};
  char *comb_name[yatzy] = {"Ones", "Twos", "Threes", "Fours", "Fives", "Sixes", "Bonus", "One pair", "Two pairs", "Three of a kind",  
                            "Four of a kind", "Small straight", "Long straight", "Full house", "Chance", "Yatzy"};
  char new_game = 'y';

  while (new_game == 'y') {
    printf("Welcome to yatzy, please enter a number of dices (5 or more) to play with: ");
    scanf("%d", &N);
    printf("\n");

    assert(N >= 5);

    result = 0;
  
    
    dice = (int*) malloc(N * sizeof(int));

    for (i = ones; i <= yatzy; i++) {
      printf ("%-16s ", comb_name[i-1]);
      
      if (i == bonus) {
        for (j = 0; j < N; j++)
          printf("- ");
      }
      else {
        roll_multiple_dice(dice, N);
        for (j = 0; j < N; j++)
          printf("%d ", dice[j]);
      }
      
      /* En switch hvor valget af operationer sker med enumeration i forhold til i */
      switch (i){
        case ones: case twos: case threes: case fours: case fives: case sixes:
          section_score = upper_check(dice, N, i);
          break;
        
        case bonus:          section_score = check_bonus(result);                           break;
        case one_pair:       section_score = identical_values(dice, N, DIE_MAX_EYES, pair); break;
        case two_pairs:      section_score = check_two_pair(dice, N, pair);                 break;
        case three_of_kind:  section_score = identical_values(dice, N, DIE_MAX_EYES, 3);    break;
        case four_of_kind:   section_score = identical_values(dice, N, DIE_MAX_EYES, 4);    break;
        case small_straight: section_score = straight(dice, N, 1, 5);                       break;
        case long_straight:  section_score = straight(dice, N, 2, 6);                       break;
        case full_house:     section_score = check_full_house(dice, N, pair);               break;
        case chance:         section_score = check_chance(dice, N);                         break;
        case yatzy:          section_score = check_yatzy(dice, N);                          break;

        default: break;
      }

      printf(": %2d \n", section_score);
      result += section_score;
    }

    printf("%-16s", "Final score");

    for (j = 0; j < N; j++)
      printf(" -");            

    printf(" : %2d \n\n", result);

    free(dice);

    printf("Would you like to play again (y/n)? ");
    scanf("\n%c", &new_game);
    assert(new_game == 'y' || new_game == 'n');
  }
}

/*
roll_multiple_dice tager det dynamiske lager og antal terninger som parametre.
Her rystes terningernes, ved at de assignes en tilfældig værdi mellem 1 og 6.
*/
void roll_multiple_dice(int dice[], int N) {
  int i;
  for (i = 0; i <= N; i++)
    dice[i] = (rand() % DIE_MAX_EYES + 1);
}

/*
I upper_check tages terningerne, antal terninger, og hvilket tal der tjekkes for som parametre.
I et loop tjekkes terningerne igennem for den ønskede værdi, og returnerer summen af dem, maks 5 terninger.
*/
int upper_check(int dice[], int N, int check) {
  int i,
      count = 0,
      sum = 0,
      found = 0;

  for (i = 0; i < N; i++){
    if (!found){
      if (dice[i] == check){
        sum += dice[i];  
        count++;
        if (count == 5) {
          found = 1;
        }
      }
    }
  }
  assert(count == sum / check);
  return sum;
}

/*
check_bonus tager øvre sektions resultat ind som parameter.
Her tjekkes der om kravet for bonussen er opnået, og returnerer den hvis det er.
*/
int check_bonus(int upper_section_result) {
  int bonus = 50;
  int bonus_req = 63;

  if (upper_section_result >= bonus_req)
    return bonus;
  else
    return 0;
}

/*
identical_values tager, terningerne, antal terninger, maximale søgeværdi, 
og antallet af identiske værdier som parameter. Her findes antallet af
terninger med samme værdi og værdisummen returneres. Denne funktion bruges til 1 par, 2 par, 3 ens, 4 ens, fullhouse.
*/
int identical_values(int dice[], int N, int max, int qty) {
  int i, j,
      score = 0,
      count = 0,
      value = 0,
      found = 0;

  for (i = max; i >= DIE_MIN_EYES; i--) {
    if (!found) {
      count = 0;

      for (j = 0; j < N; j++) {
        if (!found){
          if (dice[j] == i) {
            count++;
            if (count == qty){
              score = i * qty;
              value = i;
              found = 1;
            }
          }
        }
      }
    }
  }

  if (score)
    assert(value == score / qty);

  return score;
}

/*
check_two_pair tager terningerne, antallet af terninger og antallet af identiske værdier for et par som parametre
Her tjekkes der om der overhovedet findes 2 par i terningerne, og returnerer summen af dem hvis der er, ellers returneres 0.
*/
int check_two_pair(int dice[], int N, int pair) {
  if (identical_values(dice, N, ((identical_values(dice, N, DIE_MAX_EYES, pair) / 2) - 1), pair))
    return identical_values(dice, N, DIE_MAX_EYES, pair) + identical_values(dice, N, ((identical_values(dice, N, DIE_MAX_EYES, pair) / 2) - 1), pair);
  else 
    return 0;
}

/*
straight tager terningerne, antal terningerne, en startværdi og en slutværdi.
gennem et loop tjekkes der for om der er en terning af alle værdier i intervallet af startværdien og slutværdien.
Summen af dem returneres hvis dette opnås.
*/
int straight(int dice[], int N, int start, int end) {
  int i, j,
      score = 0,
      count = 0,
      streak = 0,
      found = 0;

  for(i = start; i <= end; i++) {
    count = 0;
    found = 0;

    for (j = 0; j < N; j++) {
      if (!found) {
        if (count < 1){
          if (dice[j] == i)
            count++; 
        }
      
        else {
          assert(count == 1);
          score += i;
          streak++;
          found = 1;
        }
      }
    }
  }

  if (streak < 5)
    score = 0;
  
  assert(score == 0 || score == 15 || score == 20);
  return score;
}

/*
check_full_house tager terningerne, antallet af terninger og antallet af identiske værdier for et par som parametre
Her tjekkes der om der er fullhouse i terningerne, og returnerer summen af fullhouse, eller 0.
*/
int check_full_house(int dice[], int N, int pair) {
  int three_of_kind = identical_values(dice, N, DIE_MAX_EYES, 3);
  int pair_high = identical_values(dice, N, DIE_MAX_EYES, pair);
  int pair_low = identical_values(dice, N, identical_values(dice, N, DIE_MAX_EYES, 3) / 3 - 1, pair);

  if (three_of_kind){
    if ((three_of_kind / 3) == (pair_high / 2)){
      if (three_of_kind && pair_low)
        return (three_of_kind + pair_low);
      
      else
        return 0;
    }
    else if ((three_of_kind / 3) < (pair_high / 2))
      return (three_of_kind + pair_high);

    else
      return 0;
  }

  else 
    return 0;
}

/*
check chance tager terningerne og antallet af terninger som parametre.
Her findes den største sum af 5 terninger blandt bunken som derefter returneres
*/
int check_chance(int dice[], int N) {
  int i, j,
      counter = 0,
      score = 0,
      found = 0;

  for (i = DIE_MAX_EYES; i >= DIE_MIN_EYES; i--) {
    if (!found){
      for (j = 0; j < N; j++) {
        if (!found) {
          if (counter < 5) {
            if (dice[j] == i){
              score += i;
              counter++;
            }
          }
          else
            found = 1;
          }
        }
    }
  }

  assert(counter == 5);
  return score;
}

/*
check_yatzy tager terningerne og antallet af terninger som parameter
Der tjekkes om der er 5 ens blandt terningerne og hvis der er returneres 50 ellers returneres 0
*/
int check_yatzy(int dice[], int N) {
  if (identical_values(dice, N, DIE_MAX_EYES, 5))
    return 50;
  else
    return 0;
}
