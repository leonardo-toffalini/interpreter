#include "include/lexer.h"
#include "include/token.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void _readChar(Lexer *l);
bool _isLetter(char ch);
char *_readIdentifier(Lexer *l);

//////////////////////////////////////////////////////////////////////
/// ******               PUBLIC FUNCTIONS                   ****** ///
//////////////////////////////////////////////////////////////////////

// create a new Lexer with the input string
Lexer get_lexer(char *inputString) {
  Lexer l;
  l.inputString = inputString;
  _readChar(&l);
  return l;
}

Token nextToken(Lexer *l) {
  Token t;

  switch (l->ch) {
  case '=':
    t = (Token){ASSIGN, "="};
    break;
  case ';':
    t = (Token){SEMICOLON, ";"};
    break;
  case '(':
    t = (Token){LPAREN, "("};
    break;
  case ')':
    t = (Token){RPAREN, ")"};
    break;
  case ',':
    t = (Token){COMMA, ","};
    break;
  case '+':
    t = (Token){PLUS, "+"};
    break;
  case '{':
    t = (Token){LBRACE, "{"};
    break;
  case '}':
    t = (Token){RBRACE, "}"};
    break;
  case 0:
    t = (Token){EOF, ""};
    break;
  default:
    if (_isLetter(l->ch)) {
      t.Literal = _readIdentifier(l);
      return t;
    } else {
      t = (Token){ILLEGAL, &l->ch};
    }
  }

  _readChar(l);
  return t;
}

//////////////////////////////////////////////////////////////////////
/// ******               PRIVATE FUNCTIONS                  ****** ///
//////////////////////////////////////////////////////////////////////

// read the next character and advance the position
void _readChar(Lexer *l) {
  if (l->readPosition >= strlen(l->inputString)) {
    l->ch = 0;
  } else {
    l->ch = l->inputString[l->readPosition];
  }
  l->position = l->readPosition;
  l->readPosition++;
}

// return true if ch is a letter
bool _is_letter(char ch) {
  return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_');
}

// read in and return the name of the identifier
char *_readIdentifier(Lexer *l) {
  int position = l->position;
  while (_isLetter(l->ch)) {
    _readChar(l);
  }
  int identifierLength = l->position - position;
  char *identifier = (char *)calloc(identifierLength, sizeof(char));
  strncpy(identifier, l->inputString + position, identifierLength);
  return identifier;
}
