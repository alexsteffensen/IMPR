#include<stdio.h>
#include<stdlib.h>

#define MAX_NAME_LGT 50
#define MAX_AMOUNT_PEOPLE 11
#define MAX_LINE_LENGTH 100    

struct person{
  char fornavn[MAX_NAME_LGT];
  char efternavn[MAX_NAME_LGT];
  char vejnavn[MAX_NAME_LGT];
  int vejnummer;
  int postnummer;
  char bynavn[MAX_NAME_LGT];
};

typedef struct person person;

int read_file(person *person, FILE *input);
void print_person(person *person, int amount);
int comp_str(const void* a, const void* b);

int main (void) {
  person p[MAX_AMOUNT_PEOPLE];
  FILE* f = fopen("adresser.txt", "r");

  int a = read_file(p, f);
  qsort(p, a, sizeof(person), comp_str);
  print_person(p,a);
  
  fclose(f);

  return EXIT_SUCCESS;
}

/* Return the amount of people read from file. */
int read_file(person *person, FILE *input) {
  char line[MAX_LINE_LENGTH];
  int i;
  for (i = 0; i < MAX_AMOUNT_PEOPLE; i++){
    fgets(line, MAX_LINE_LENGTH, input);
    sscanf(line, " %s %[^,], %[^0123456789] %d, %d %[^.].",
           (person+i)->fornavn, (person+i)->efternavn, (person+i)->vejnavn, 
           &(person+i)->vejnummer, &(person+i)->postnummer, (person+i)->bynavn);
    if (feof(input))
      return i;
  }
  return i; 
}

void print_person(person *person, int amount) {
  int i;
  for (i = 0; i < amount; i++)
  {
    printf("%-8s : %s \n", (person+i)->bynavn, (person+i)->efternavn);
  }
}

int comp_str(const void* a, const void* b) {
  int res;
  char *c1 = ((person*)a)->efternavn, *c2 = ((person*)b)->efternavn;
  
  while (*c1 != '\0' && *c2 != '\0'){
    res = *c1++ - *c2++;
    if (res != 0)
      return res;
  }
  
  return res;

}

