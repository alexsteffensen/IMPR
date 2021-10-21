#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void sort_product_code(char *product_code, int length, char *warehouse, char *product, char *qualifiers);

/* i main køres funktionen der sorterer produktkoden, og den sorterede kode printes derefter. */
int main(void) {
  char product_code[10] = "ATL1203S14",
       warehouse[4] = "",
       product[5] = "",
       qualifiers[4] = "";

  sort_product_code(product_code, 10, warehouse, product, qualifiers);

  printf("Warehouse: %s \nProduct: %s \nQualifiers: %s \n", warehouse, product, qualifiers);

  return EXIT_SUCCESS;
}

/* Sorterer productkoden gennem funktionen under */
void sort_product_code(char *product_code, int length, char *warehouse, char *product, char *qualifiers){
  int i,
      sorted = 0,
      warehouse_stop;
  
  /* her sorteres til varehus koden. isdigit() er true hvis den finder et tal i string */
  for (i = 0; i <= length; i++){
    if (!sorted){
      if (isdigit(product_code[i])){
        strncpy(warehouse, product_code, i);
        sorted = 1;
        warehouse_stop = i;
      }
      continue;
    }
  }  

  sorted = 0;
  
  /* her sorteres produktkoden og kvalifikations koden. isalpha() er true hvis det er en bogstav */
  for (i = warehouse_stop; i <= length; i++){
    if (!sorted){
      if (isalpha(product_code[i])) {
          strncpy(product, product_code + warehouse_stop, i - warehouse_stop);
          strncpy(qualifiers, product_code + i, length - i);
          sorted = 1;
        }
    }
  }
}




