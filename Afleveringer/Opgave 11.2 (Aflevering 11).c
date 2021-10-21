#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_palindrome_iter(char *str);
int is_palindrome_rec(char *str);
int is_palindrome_rec_2(int front, int back, char *str);

/* main kører dialog med bruger og palindrom funktionen */
int main(void) {
  char word[30];

  printf("Write a word, and see if it is a palindrome: ");
  scanf("%s", word);
  
  if (is_palindrome_rec(word))
    printf("It is a palindrome!\n");
  else
    printf("It is not a palindrome!\n");

  return EXIT_SUCCESS;
}

/* funktionen der finder ud af om det er en palindrom 
eller ej gennem en iterativ kontrolstruktur */
int is_palindrome_iter(char *str){
  int i;
  int string_len = strlen(str) - 1;

  for (i = 0; i <= string_len / 2; i++) {
    if (str[i] == str[string_len-i])
      continue;
    else
      return 0;
  }

  return 1;
}

/* funktionen der returnerer værdien af den rekursive funktion */
int is_palindrome_rec(char *str) {
  int i = 0;
  int string_len = strlen(str) - 1;

  return is_palindrome_rec_2(i, string_len, str);  
}

/* Den rekursive funktion som finder ud af om det er en palindrom
 eller ej ved brug af rekursion, da den kalder sig selv igen. */
int is_palindrome_rec_2(int front, int back, char *str) {
  if (str[front] == str[back])
    return (front == (strlen(str) - 1) / 2) ? 1 : is_palindrome_rec_2(front + 1, back - 1, str);
  else
    return 0;
}








