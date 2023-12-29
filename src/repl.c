#include <stdbool.h>
#include <stdio.h>
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

    Lexer l = initLexer(input);

    while (true) {
      Token t = nextToken(&l);
      if (t.Type == EOF_T) {
        return;
      }
      char *typeString = tokenToString(t.Type);
      printf("{Type: %s, Literal: '%s'}\n", typeString, t.Literal);
    }
  }
}
