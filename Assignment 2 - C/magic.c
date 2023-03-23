/**
 * Magic squares program
 * Uses a 2-D array to implement the Siamese method for constructing magic
 * squares Efe Comu
 */
#include <stdio.h>

int main(int argc, char *argv[]) {

  int n;

  printf("Enter an odd value: ");
  int rc = scanf("%d", &n);
  if (rc < 0) {
    perror("Something went wrong.");
  }

  if (n % 2 == 0) {
    perror("The number is not odd.");
    return -1;
  } else {
    int MagicArray[n][n];

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        MagicArray[i][j] = 0;
      }
    }
    int row = 0;
    int col = n / 2;

    for (int i = 1; i <= n * n; i++) {

      MagicArray[row][col] = i;
      // Initiate 2 variables to keep track of row and col
      int x = row - 1;
      int y = col + 1;
      // Calculate the position that would be found if we moved up
      // and right, wrapping around if necessary
      if (x < 0) {
        x = n - 1;
      }
      if (y > (n - 1)) {
        y = 0;
      }
      // Check if that square is occupied
      // If it's not, update row and col to the new position
      // If it is occupied, move down instead, and update row and col
      // accordingly for the next iteration
      if (MagicArray[x][y] == 0) {
        row = x;
        col = y;
      } else {
        row++;
      }
    }

    // Print the complete square

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        printf("%d  ", MagicArray[i][j]);
      }
      printf("\n");
    }
    printf("\n");
  }
}
