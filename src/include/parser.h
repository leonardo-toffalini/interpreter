#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "statement.h"
#include "token.h"
#include <stdbool.h>

typedef struct Parser {
  Lexer *l;
  Token curToken;
  Token peekToken;
  char errors[64][256]; // list of strings
  int numErrors;
} Parser;

Parser *initParser(Lexer *l);
StatementList parseProgram(Parser *p);
bool checkParserErrors(Parser *p);

#endif // !PARSER_H
