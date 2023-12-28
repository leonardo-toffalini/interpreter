#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "../include/lexer.h"
#include "lexer_test.h"

void test_simple() {
  char *input = "=+(){},;\n";
  printf("input: %s", input);

  Token tests[] = {
      {.Type = ASSIGN, .Literal = "="}, {.Type = PLUS, .Literal = "+"},
      {.Type = LPAREN, .Literal = "("}, {.Type = RPAREN, .Literal = ")"},
      {.Type = LBRACE, .Literal = "{"}, {.Type = RBRACE, .Literal = "}"},
      {.Type = COMMA, .Literal = ","},  {.Type = SEMICOLON, .Literal = ";"},
  };

  Lexer l = initLexer(input);
  bool passed = true;
  int i = 0;

  while (true) {
    Token t = nextToken(&l);
    if (t.Type == EOF_T) {
      break;
    }

    if (t.Type != tests[i].Type) {
      printf("Char #%d\n", i);
      printf("%d != %d\n", t.Type, tests[i].Type);
      passed = false;
    }
    if (strcmp(t.Literal, tests[i].Literal) != 0) {
      printf("Char #%d\n", i);
      printf("%s != %s\n", t.Literal, tests[i].Literal);
      passed = false;
    }
    // else {
    //     printf("%s == %s\n", cur_token.value, tests[i].value);
    // }
    i++;
  }
  if (passed) {
    printf("Passed!\n");
  } else {
    printf("Failed!\n");
  }
}

void test_code() {
  char *input = "let five = 5;\n"
                "let ten = 10;\n"
                "let add = fn(x, y) {\n"
                "   x + y;\n"
                "};\n"
                "\n"
                "let result = add(five, ten);\n"
                "!-/*5;\n"
                "5 < 10 > 5;\n"
                "\n"
                "if (5 < 10) {\n"
                "    return true;\n"
                "} else {\n"
                "    return false;\n"
                "}\n"
                "\n"
                "10 == 10;\n"
                "10 != 9;\n";

  Token tests[] = {
      {.Type = LET, .Literal = "let"},
      {.Type = IDENT, .Literal = "five"},
      {.Type = ASSIGN, .Literal = "="},
      {.Type = INT, .Literal = "5"},
      {.Type = SEMICOLON, .Literal = ";"},
      {.Type = LET, .Literal = "let"},
      {.Type = IDENT, .Literal = "ten"},
      {.Type = ASSIGN, .Literal = "="},
      {.Type = INT, .Literal = "10"},
      {.Type = SEMICOLON, .Literal = ";"},
      {.Type = LET, .Literal = "let"},
      {.Type = IDENT, .Literal = "add"},
      {.Type = ASSIGN, .Literal = "="},
      {.Type = FUNCTION, .Literal = "fn"},
      {.Type = LPAREN, .Literal = "("},
      {.Type = IDENT, .Literal = "x"},
      {.Type = COMMA, .Literal = ","},
      {.Type = IDENT, .Literal = "y"},
      {.Type = RPAREN, .Literal = ")"},
      {.Type = LBRACE, .Literal = "{"},
      {.Type = IDENT, .Literal = "x"},
      {.Type = PLUS, .Literal = "+"},
      {.Type = IDENT, .Literal = "y"},
      {.Type = SEMICOLON, .Literal = ";"},
      {.Type = RBRACE, .Literal = "}"},
      {.Type = SEMICOLON, .Literal = ";"},
      {.Type = LET, .Literal = "let"},
      {.Type = IDENT, .Literal = "result"},
      {.Type = ASSIGN, .Literal = "="},
      {.Type = IDENT, .Literal = "add"},
      {.Type = LPAREN, .Literal = "("},
      {.Type = IDENT, .Literal = "five"},
      {.Type = COMMA, .Literal = ","},
      {.Type = IDENT, .Literal = "ten"},
      {.Type = RPAREN, .Literal = ")"},
      {.Type = SEMICOLON, .Literal = ";"},
      {.Type = BANG, .Literal = "!"},
      {.Type = MINUS, .Literal = "-"},
      {.Type = SLASH, .Literal = "/"},
      {.Type = ASTERISK, .Literal = "*"},
      {.Type = INT, .Literal = "5"},
      {.Type = SEMICOLON, .Literal = ";"},
      {.Type = INT, .Literal = "5"},
      {.Type = LT, .Literal = "<"},
      {.Type = INT, .Literal = "10"},
      {.Type = GT, .Literal = ">"},
      {.Type = INT, .Literal = "5"},
      {.Type = SEMICOLON, .Literal = ";"},
      {.Type = IF, .Literal = "if"},
      {.Type = LPAREN, .Literal = "("},
      {.Type = INT, .Literal = "5"},
      {.Type = LT, .Literal = "<"},
      {.Type = INT, .Literal = "10"},
      {.Type = RPAREN, .Literal = ")"},
      {.Type = LBRACE, .Literal = "{"},
      {.Type = RETURN, .Literal = "return"},
      {.Type = TRUE, .Literal = "true"},
      {.Type = SEMICOLON, .Literal = ";"},
      {.Type = RBRACE, .Literal = "}"},
      {.Type = ELSE, .Literal = "else"},
      {.Type = LBRACE, .Literal = "{"},
      {.Type = RETURN, .Literal = "return"},
      {.Type = FALSE, .Literal = "false"},
      {.Type = SEMICOLON, .Literal = ";"},
      {.Type = RBRACE, .Literal = "}"},
      {.Type = INT, .Literal = "10"},
      {.Type = EQ, .Literal = "=="},
      {.Type = INT, .Literal = "10"},
      {.Type = SEMICOLON, .Literal = ";"},
      {.Type = INT, .Literal = "10"},
      {.Type = NOT_EQ, .Literal = "!="},
      {.Type = INT, .Literal = "9"},
      {.Type = SEMICOLON, .Literal = ";"},
      {.Type = EOF_T, .Literal = "\0"},
  };

  Lexer l = initLexer(input);
  int i = 0;
  bool passed = true;

  while (true) {
    Token t = nextToken(&l);
    if (t.Type == EOF_T) {
      break;
    }

    if (t.Type != tests[i].Type) {
      printf("Char #%d\n", i);
      printf("%d != %d\n", t.Type, tests[i].Type);
      passed = false;
    }
    if (strcmp(t.Literal, tests[i].Literal) != 0) {
      printf("Char #%d\n", i);
      printf("%s != %s\n", t.Literal, tests[i].Literal);
      passed = false;
    }
    // else {
    //     printf("%s == %s\n", cur_token.value, tests[i].value);
    // }
    i++;
  }
  if (passed) {
    printf("Passed!\n");
  } else {
    printf("Failed!\n");
  }
}

void run_all_lexer_tests() {
  printf("Test Simple:\n");
  test_simple();

  printf("Test Code:\n");
  test_code();
}
