typedef struct Lexer {
  char *inputString;
  int position;
  int readPosition;
  char ch;
} Lexer;

Lexer get_lexer(char *inputString);
