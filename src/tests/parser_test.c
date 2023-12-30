#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "../include/parser.h"
#include "parser_test.h"

bool testLetStatement(Statement s, char *name) {
  if (s.type != LET_STMT) {
    printf("Identifier is not a let statement\n");
    return false;
  }

  LetStatement let = s.data.let;
  if (let.identifier.Type != IDENT) {
    printf("Identifier is not an IDENT token\n");
    return false;
  }
  if (strcmp(let.identifier.Literal, name) != 0) {
    printf("Discovered ident name doesn't equal expected name: '%s' != '%s'\n",
           let.identifier.Literal, name);
    return false;
  }
  return true;
}

bool testBadLetStatements() {
  char input_string[] = "let x 5;\n"
                        "let = 10;\n"
                        "let 838383 = x;\n";

  Lexer l = initLexer(input_string);
  Parser p = initParser(&l);

  parseProgram(&p);
  // Make sure we got some errors up in here
  assert(!checkParserErrors(&p));
  return true;
}

bool testLetStatements() {
  char input_string[] = "let x = 5;\n"
                        "let y = 10;\n"
                        "let foobar = 838383;\n";

  Lexer l = initLexer(input_string);
  Parser p = initParser(&l);

  StatementList prog = parseProgram(&p);
  assert(checkParserErrors(&p));
  if (prog.count == 0) {
    printf("parse_program has no statements");
    return false;
  }
  if (prog.count != 3) {
    printf("parse_program did not collect 3 statements. Got %lu", prog.count);
    return false;
  }

  // Assign cur statement to next item in linked list
  testLetStatement(prog.statements[0], "x");
  testLetStatement(prog.statements[1], "y");
  testLetStatement(prog.statements[2], "foobar");
  return true;
}

void runAllParserTests() {
  assert(testLetStatements());
  assert(testBadLetStatements());
  if (testBadLetStatements() && testLetStatements())
    printf("Parser tests ran successfully!\n");
}
