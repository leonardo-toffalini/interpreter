#ifndef TOKEN_H
#define TOKEN_H

typedef enum {
  ILLEGAL,
  EOF,

  // Identifiers + literals
  IDENT,
  INT,

  // Operators
  ASSIGN,
  PLUS,

  // Delimiters
  COMMA,
  SEMICOLON,

  LPAREN,
  RPAREN,
  LBRACE,
  RBRACE,

  // Keywords
  FUNCTION,
  LET,
} TokenType;

typedef struct Token {
  TokenType Type;
  char *Literal;
} Token;

#endif // !TOKEN_H
