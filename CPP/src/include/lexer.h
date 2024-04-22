#ifndef LEXER_H
#define LEXER_H

#include "token.h"
#include <string>

class Lexer {
private:
  std::string input;
  int position;
  int readPosition;
  char ch;

public:
  Lexer(std::string in) {
    input = in;
    readChar();
  }

  void readChar();

  Token nextToken();

  std::string readIdentifier();
};

#endif // !LEXER_H
