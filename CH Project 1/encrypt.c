/**
 * Implement Polybius square encryption
 * Efe Comu / Andrea Diaz Guma
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char s, char x[5][5]) {
  int row, col;

  if (s == 'q') {
    s = 'i';
  }

  for (row = 0; row < 5; row++) {
    for (col = 0; col < 5; col++) {

      if ((s - '0') == (x[row][col] - '0')) {
        printf("%d%d", row, col);
      }
    }
  }
}

int main(int argc, char *argv[]) {

  char buf[250];
  printf("Enter a text: ");
  char *str = fgets(buf, 250, stdin);

  char table[5][5] = {{'l', 'a', 'b', 'o', 'r'},
                      {'c', 'd', 'e', 'f', 'g'},
                      {'h', 'i', 'j', 'k', 'm'},
                      {'n', 'p', 's', 't', 'u'},
                      {'v', 'w', 'x', 'y', 'z'}};

  for (int i = 0; str[i] != '\0'; i++) {
    encrypt(str[i], table);
  }
  printf("\n");
}
