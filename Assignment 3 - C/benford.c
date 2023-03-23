/**
 * Validating Benford's Law
 */

// Use this file to implement the program that reads
// Census data and compares the distribution of population
// digits to Benford's Law
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

  // Open the file
  FILE *f = fopen("co-est2021-alldata.csv", "r");

  // Check the return code
  if (f == NULL) {
    perror("fopen");
    exit(1);
  }

  // Declare character buffer
  char buf[1024];

  int firstLine = 1;
  double nLines = 0;
  int counts[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  // Loop over the remaining lines that have data
  while (fgets(buf, sizeof(buf), f) != NULL) {

    // Skip the first line that contains the field names
    if (firstLine) {
      firstLine = 0;
      continue;
    }

    // Use strtok to get the first value
    char *token;
    token = strtok(buf, ",");

    // Get the second token -- strtok keep processing the same string if its
    // first input is NULL
    for (int i = 0; i < 9; i++) {
      token = strtok(NULL, ",");
    }

    // Get the first digit
    char firstDigit = *token;

    int value = firstDigit - '0';
    counts[value]++;

    nLines++;
  }

  for (int i = 0; i < 10; i++) {
    double fraction = counts[i] / nLines;

    printf("Fraction of leading %d's = %0.4f\n", i, fraction);
  }
}
