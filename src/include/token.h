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
  EQ,
  PLUS,
  MINUS,
  BANG,
  NOT_EQ,
  ASTERISK,
  SLASH,

  LT,
  GT,

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
  TRUE,
  FALSE,
  IF,
  ELSE,
  RETURN
} TokenType;

typedef struct Token {
  TokenType Type;
  char *Literal;
} Token;

TokenType lookupIdentifier(char *identifier);

#endif // !TOKEN_H
