#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "statement.h"
#include "token.h"
#include <cstddef>

typedef struct Parser {
  Lexer *l;
  Token curToken;
  Token peekToken;
} Parser;

Parser *initParser(Lexer *l);
StatementList parseProgram(Parser *p);

#endif // !PARSER_H
