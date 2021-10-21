#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKS 10
#define TITLE_MAX 50
#define AUTHOR_MAX 40
#define PUBLISHER_MAX 20

struct book {
  char title[TITLE_MAX], author[AUTHOR_MAX], publisher[PUBLISHER_MAX];
  int publishing_year;
  int university_text_book;
};

typedef struct book book;

void sort_books_by_title(book *shelf, int len);
int compbook(const void* a, const void* b);
void sort_books_by_kind(book *shelf, int len);
int comp_kind_year(const void* a, const void* b);


book make_book(char *title, char *author, char *publisher, int year, int text_book);
void prnt_book(book b);

int main(void) {
  book shelf[MAX_BOOKS];
  int i;

  shelf[0] =
    make_book("Problem Solving and Program Design in C", "Hanly and Koffman", 
              "Pearson", 2010, 1);   

  shelf[1] =
    make_book("C by Disssection", "Kelley and Pohl", 
              "Addison Wesley", 2001, 1);   

  shelf[2] =
    make_book("The C Programming Language", "Kernighan og Ritchie", 
              "Prentice Hall", 1988, 1);   

  shelf[3] =
    make_book("Pelle Erobreren", "Martin Andersen Nexoe",
              "Gyldendal", 1910, 0);

  shelf[4] = shelf[3];
  strcpy(shelf[4].title, "Ditte Menneskebarn");
  shelf[4].publishing_year = 1917;

  sort_books_by_kind(shelf, 5);

  for(i = 0; i <=4; i++)
    prnt_book(shelf[i]);
  
  return EXIT_SUCCESS;
}


book make_book(char *title, char *author, char *publisher, int year, int text_book){
  book result;
  strcpy(result.title, title); strcpy(result.author, author); strcpy(result.publisher, publisher); 
  result.publishing_year = year;
  result.university_text_book = text_book;
 
    return result;
}

void prnt_book(book b){
  char *yes_or_no;

  yes_or_no = (b.university_text_book ? "yes" : "no"); 
  printf("Title: %s\n"
         "Author: %s\n"
         "Publisher: %s\n"
         "Year: %4i\n"
         "University text book: %s\n\n",
         b.title, b.author, b.publisher, 
         b.publishing_year, yes_or_no);
}

void sort_books_by_title(book *shelf, int len) {
  qsort(shelf, len, sizeof(book), compbook);
}

void sort_books_by_kind(book *shelf, int len) {
  qsort(shelf, len, sizeof(book), comp_kind_year);
}

int comp_kind_year(const void* a, const void* b) {
  int kind1 = ((book*)a)->university_text_book, kind2 = ((book*)b)->university_text_book;
  int year1 = ((book*)a)->publishing_year, year2 = ((book*)b)->publishing_year;

  if (kind1 == kind2)
    return year1 - year2;
  else
    return kind1 - kind2;

}

int compbook(const void* a, const void* b) {
  int res;
  char *c1 = ((book*)a)->title, *c2 = ((book*)b)->title;

  do
    res = *c1++ - *c2++;
  while(res == 0);

  return res;
}
