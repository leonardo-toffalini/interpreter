#ifndef LEXER_H
#define LEXER_H

#include "token.h"
#include <stdbool.h>

typedef struct Lexer {
  char *inputString;
  int position;
  int readPosition;
  char ch;
} Lexer;

Lexer initLexer(char *inputString);
Token nextToken(Lexer *l);

#endif // !LEXER_H
