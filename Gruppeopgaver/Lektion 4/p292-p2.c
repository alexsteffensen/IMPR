#include <stdio.h>
#include <stdlib.h>

int main() {
  int count = 0, size;

  printf("%s\n",
    "Given a size, prints a pyramid of said size",
    "Input size: ");
  scanf(" %d", &size);

  for (size_t i = 0; count < size * 2 + 1; count > size ? i-- : i++) {
    printf("\n");
    count++;
    for (size_t j = 0; j <= size; j++) {
      if(i >= j)
        printf("%d ", j);
    }
  }
  return EXIT_SUCCESS;
}
