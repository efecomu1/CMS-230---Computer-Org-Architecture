// Tales from the Crypt

#include <crypt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *compare(char *inputHash, char *file) {

  FILE *f = fopen(file, "r");

  if (f == NULL) {
    perror("fopen");
    exit(1);
  }

  char *buf = malloc(1024 * sizeof(char));

  while (fgets(buf, sizeof(buf), f) != NULL) {

    char *salt = "$1$";
    char *hashedWord = crypt(buf, salt);

    // printf("input Hash:  |%s|\n", inputHash);
    // printf("dictionary Hash:  |%s|\n", hashedWord);

    if (strcmp(hashedWord, inputHash) == 0) {
      printf("%s\n", hashedWord);
      return buf;
    }
  }
  return NULL;
}

int main(int argc, char *argv[]) {

  //*** Process input arguments ***//

  char *input = NULL;
  char *output = NULL;
  char *dictionary = NULL;

  int n = 0;
  int c = 0;
  char a;

  while ((a = getopt(argc, argv, "i:o:d:nc")) != -1) {
    if (a == 'i') {
      input = optarg;
    }
    if (a == 'o') {
      output = optarg;
    }
    if (a == 'd') {
      dictionary = optarg;
    }
    if (a == 'n') {
      n = 1;
    }
    if (a == 'c') {
      c = 1;
    }
  }

  //*** You do the rest ***//

  // Open the file
  FILE *f = fopen(input, "r");

  // Check the return code
  if (f == NULL) {
    perror("fopen");
    exit(1);
  }

  // declare character buffer
  char buffer[1024];

  while (fgets(buffer, sizeof(buffer), f) != NULL) {

    char *key = strtok(buffer, ":");
    printf("user: %s ", key);

    key = strtok(NULL, " ");
    printf("hashed pass: %s", key);

    char *word = compare(key, dictionary);
    if (word != NULL) {
      printf("Word: %s", word);
      printf("\n");
      break;
    }
  }
  printf("\n");

  return 0;
}
