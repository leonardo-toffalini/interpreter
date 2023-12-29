#include "lexer_test.h"
#include "parser_test.h"
#include <stdio.h>

int main() {
  runAllLexerTests();
  runAllParserTests();
  printf("done\n");
  return 0;
}
