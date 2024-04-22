#include "include/lexer.h"
#include "include/token.h"

bool isLetter(char ch) {
  return 'a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z' || ch == '_';
}

void Lexer::readChar() {
  if (readPosition >= input.length())
    ch = 0;
  else
    ch = input[readPosition];

  position = readPosition;
  ++readPosition;
}

Token Lexer::nextToken() {
  Token tok;

  switch (ch) {
  case '=':
    tok = Token(ASSIGN, ch);
    break;

  case ';':
    tok = Token(SEMICOLON, ch);
    break;

  case '(':
    tok = Token(LPAREN, ch);
    break;

  case ')':
    tok = Token(RPAREN, ch);
    break;

  case ',':
    tok = Token(COMMA, ch);
    break;

  case '+':
    tok = Token(PLUS, ch);
    break;

  case '{':
    tok = Token(LBRACE, ch);
    break;

  case '}':
    tok = Token(RBRACE, ch);
    break;

  case 0:
    tok = Token(EOF_T, ch);
    break;

  default:
    if (isLetter(ch)) {
      tok.literal = readIdentifier();
      return tok;
    } else {
      tok = Token(ILLEGAL, ch);
    }
  }

  readChar();
  return tok;
}

std::string Lexer::readIdentifier() {
  int start = position;
  while (isLetter(ch))
    readChar();

  return input.substr(start, position);
}
