/**
 * Implement Polybius square decryption
 * Efe Comu / Andrea Diaz Guma
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decrypt(char *n, char x[5][5]) {
  // Efe
  // int tempnum = n;
  // int length = 0;
  // while (tempnum != 0) {
  // tempnum /= 10;
  // length++;
  // }
  int row, col;
  for (int i = 0; n[i] != '\0'; i++) {

    if (i % 2 == 1) {

      row = n[i - 1] - '0';
      col = n[i] - '0';

      printf("%c", x[row][col]);
    }
  }

}

int main(int argc, char *argv[]) {

  char buf[250];
  printf("Enter digits: ");
  char *num = fgets(buf, 250, stdin);

  // int number = atoi(num);

  char table[5][5] = {{'l', 'a', 'b', 'o', 'r'},
                      {'c', 'd', 'e', 'f', 'g'},
                      {'h', 'i', 'j', 'k', 'm'},
                      {'n', 'p', 's', 't', 'u'},
                      {'v', 'w', 'x', 'y', 'z'}};

  decrypt(num, table);
  printf("\n");
}
