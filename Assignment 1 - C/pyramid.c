/**
Write a function called pyramid that takes an int n as input and prints a
pyramid of n levels
*
Efe Comu
*/

#include <stdio.h>

void pyramid(int n) {

  int numSpaces;
  int numStars;

  for (int level = 1; level <= n; level++) {

    for (numSpaces = 0; numSpaces <= n - level; numSpaces++) {

      printf(" ");
    }

    for (numStars = 1; numStars <= 2 * level - 1; numStars++) {

      printf("*");
    }
    printf("\n");
  }
}

void hollow(int n) {

  for (int level = 1; level <= n; level++) {

    for (int numSpaces = 0; numSpaces <= n - level; numSpaces++) {

      printf(" ");
    }

    if (level == 1 || level == n) {

      for (int numStars = 1; numStars <= 2 * level - 1; numStars++) {

        printf("*");
      }
    } else {
      printf("*");
      for (int numSpaces = 1; numSpaces <= 2 * level - 3; numSpaces++) {
        printf(" ");
      }
      printf("*");
    }
    printf("\n");
  }
}

int main(int argc, char *argv[]) {
  pyramid(10);
  hollow(10);
}
