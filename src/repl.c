#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/lexer.h"
#include "include/repl.h"
#include "include/token.h"

void start() {
  Lexer l;
  char input[100];
  while (true) {
    printf(">> ");
    fgets(input, 1024, stdin);

    if (strcmp(input, "") == 0) {
      return;
    }

    Lexer l = getLexer(input);

    Token t = nextToken(&l);
    char *typeString = tokenToString(t.Type);

    while (true) {
      Token t = nextToken(&l);
      if (t.Type == EOF_T) {
        return;
      }
      char *typeString = tokenToString(t.Type);
      printf("{Type: %s, Value: '%s'}\n", typeString, t.Literal);
    }
  }
}
