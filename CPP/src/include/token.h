#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum TokenType {
  ILLEGAL,
  EOF_T,

  IDENT,
  INT,

  ASSIGN,
  PLUS,

  COMMA,
  SEMICOLON,

  LPAREN,
  RPAREN,
  LBRACE,
  RBRACE,

};

class Token {
public:
  TokenType type;
  std::string literal;

  Token() = default;

  Token(TokenType t, char ch) {
    type = t;
    literal = std::string(1, ch);
  }
};

#endif // !TOKEN_H
