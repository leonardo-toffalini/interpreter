#include "include/token.h"
#include <stdlib.h>
#include <string.h>

TokenType lookupIdentifier(char *identifier) {
  {
    if (strcmp(identifier, "fn") == 0) {
      return FUNCTION;
    } else if (strcmp(identifier, "let") == 0) {
      return LET;
    } else if (strcmp(identifier, "true") == 0) {
      return TRUE;
    } else if (strcmp(identifier, "false") == 0) {
      return FALSE;
    } else if (strcmp(identifier, "if") == 0) {
      return IF;
    } else if (strcmp(identifier, "else") == 0) {
      return ELSE;
    } else if (strcmp(identifier, "return") == 0) {
      return RETURN;
    } else {
      return IDENT;
    }
  }
}

char *tokenToString(TokenType t) {
  char *token_string = calloc(10, 1);

  switch (t) {
  case ILLEGAL:
    strcpy(token_string, "ILLEGAL");
    break;
  case EOF_T:
    strcpy(token_string, "EOF_T");
    break;
  case IDENT:
    strcpy(token_string, "IDENT");
    break;
  case INT:
    strcpy(token_string, "INT");
    break;
  case ASSIGN:
    strcpy(token_string, "ASSIGN");
    break;
  case PLUS:
    strcpy(token_string, "PLUS");
    break;
  case MINUS:
    strcpy(token_string, "MINUS");
    break;
  case BANG:
    strcpy(token_string, "BANG");
    break;
  case ASTERISK:
    strcpy(token_string, "ASTERISK");
    break;
  case SLASH:
    strcpy(token_string, "SLASH");
    break;
  case LT:
    strcpy(token_string, "LT");
    break;
  case GT:
    strcpy(token_string, "GT");
    break;
  case EQ:
    strcpy(token_string, "EQ");
    break;
  case NOT_EQ:
    strcpy(token_string, "NOT_EQ");
    break;
  case COMMA:
    strcpy(token_string, "COMMA");
    break;
  case SEMICOLON:
    strcpy(token_string, "SEMICOLON");
    break;
  case LPAREN:
    strcpy(token_string, "LPAREN");
    break;
  case RPAREN:
    strcpy(token_string, "RPAREN");
    break;
  case LBRACE:
    strcpy(token_string, "LBRACE");
    break;
  case RBRACE:
    strcpy(token_string, "RBRACE");
    break;
  case FUNCTION:
    strcpy(token_string, "FUNCTION");
    break;
  case LET:
    strcpy(token_string, "LET");
    break;
  case TRUE:
    strcpy(token_string, "TRUE");
    break;
  case FALSE:
    strcpy(token_string, "FALSE");
    break;
  case IF:
    strcpy(token_string, "IF");
    break;
  case ELSE:
    strcpy(token_string, "ELSE");
    break;
  case RETURN:
    strcpy(token_string, "RETURN");
    break;
  }

  return token_string;
}
