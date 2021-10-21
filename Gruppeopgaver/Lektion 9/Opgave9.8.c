#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIE_MAX_EYES 6

void roll_multiple_dices(int dices[], int N);

int main(void) {
  int N;
  
  srand(time(NULL));

  for (int i = 0; i <= 10; i++){
    printf("Please enter a number of dices: ");
    scanf("%d", &N);

    int dices[N];

    roll_multiple_dices(dices, N);
    
    for (int j = 0; j < N; j++){
      printf("dice[%d] = %d\n", j, dices[j]);
    }
  }
   
}

void roll_multiple_dices(int dices[], int N) {
  
  for (int i = 0; i <= N; i++) 
    dices[i] = (rand() % DIE_MAX_EYES + 1);
}




