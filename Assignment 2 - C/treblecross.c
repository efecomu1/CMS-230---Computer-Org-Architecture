/**
 * Treblecross
 * Efe Comu
 */

#include <stdio.h>

int n;

void PrintArray(char x[]) {
  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("| %c ", x[i]);
  }
  printf("|");
  printf("\n");
}

int player = 1;
int gameIP = 1;
int move;

void Winner(char x[]) {
  PrintArray(x);
  printf("Player "
         "%d"
         " wins!!",
         player);
  gameIP = 0;
}

int main(int argc, char *argv[]) {

  printf("Welcome to Treblecross!!\n");
  printf("Type the size of the board you want to play "
         "the game on: ");
  int rc = scanf("%d", &n);
  if (rc < 0) {
    perror("Something went wrong.");
  }

  if (n <= 0) {
    perror("Error. The size has to be a positive number.");
    return -1;
  }

  else {
    char BoardArray[n];

    for (int i = 0; i < n; i++) {
      BoardArray[i] = '-';
    }

    // Main game while loop
    while (gameIP) {

      printf("Current board: ");
      PrintArray(BoardArray);

      printf("Player "
             "%d"
             " please choose an empty index to mark an 'X': ",
             player);
      rc = scanf("%d", &move);
      if (rc < 0) {
        perror("Something went wrong.");
      }
      if (BoardArray[move] != '-' || move < 0 || move > n - 1) {
        printf("Invalid move! Try again. ");
        player = (player % 2) + 1;
      } else {
        BoardArray[move] = 'X';
      }
      // Checking the winning conditions without accessing any location outside
      // of the array
      if (move == 0) {
        if (BoardArray[move + 1] == 'X' && BoardArray[move + 2] == 'X') {
          Winner(BoardArray);
        } else {
          // player = (player % 2) + 1;
        }
      } else if (move == 1) {
        if (BoardArray[move - 1] == 'X' && BoardArray[move + 1] == 'X') {
          Winner(BoardArray);

        } else if (BoardArray[move + 1] == 'X' && BoardArray[move + 2] == 'X') {
          Winner(BoardArray);
        } else {
          // player = (player % 2) + 1;
        }

      } else if (move == (n - 2)) {
        if (BoardArray[move - 1] == 'X' && BoardArray[move + 1] == 'X') {
          Winner(BoardArray);

        } else if (BoardArray[move - 1] == 'X' && BoardArray[move - 2] == 'X') {
          Winner(BoardArray);
        } else {
          // player = (player % 2) + 1;
        }

      } else if (move == (n - 1)) {
        if (BoardArray[move - 1] == 'X' && BoardArray[move - 2] == 'X') {
          Winner(BoardArray);
        } else {
          // player = (player % 2) + 1;
        }
      } else {
        if (BoardArray[move - 1] == 'X' && BoardArray[move - 2] == 'X') {
          Winner(BoardArray);
        } else if (BoardArray[move - 1] == 'X' && BoardArray[move + 1] == 'X') {
          Winner(BoardArray);
        } else if (BoardArray[move + 1] == 'X' && BoardArray[move + 2] == 'X') {
          Winner(BoardArray);
        }
      }
      player = (player % 2) + 1;
      printf("\n");
    }
  }
}
