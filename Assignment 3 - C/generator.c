/**
 * Generating random data
 */

// Use this file to implement the program that generates
// random data with first digits obeying Benford's Law

// for (int i = 0; i < argc; i++) {
// printf("%s\n", argv[i]);
// }
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int benfordDigit() {
  double r = ((double)rand()) / RAND_MAX;

  if (r < 0.3010) {
    r = 1;
  } else if (r < 0.4770) {
    r = 2;
  } else if (r < 0.602) {
    r = 3;
  } else if (r < 0.6990) {
    r = 4;
  } else if (r < 0.7780) {
    r = 5;
  } else if (r < 0.8450) {
    r = 6;
  } else if (r < 0.9030) {
    r = 7;
  } else if (r < 0.9540) {
    r = 8;
  } else if (r < 1) {
    r = 9;
  }
  return r;
}

int uniformDigit() { return rand() % 10; }

int main(int argc, char *argv[]) {

  int numValues = 0;
  int numDigits = 10;

  // Process arguments with getopt
  int c;
  while ((c = getopt(argc, argv, "n:d:")) != -1) {
    switch (c) {
    case 'n':
      numValues = atoi(optarg);
      break;
    case 'd':
      numDigits = atoi(optarg);
      break;
    }
  }
  // printf("%d\n", numValues);
  // printf("%d\n", numDigits);

  for (int n = 0; n < numValues; n++) {
    int result = benfordDigit();

    for (int d = 0; d < numDigits - 1; d++) {
      result = result * 10 + uniformDigit();
    }

    printf("%d\n", result);
  }
}
