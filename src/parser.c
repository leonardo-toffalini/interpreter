#include "include/parser.h"
#include "include/ast.h"
#include "include/lexer.h"
#include "include/statement.h"
#include "include/token.h"

void _parserNextToken(Parser *p);
Statement _parseStatement(Parser *p);
Statement _parseLetStatement(Parser *p);

Parser *initParser(Lexer *l) {
  Parser *p;

  _parserNextToken(p);
  _parserNextToken(p);

  return p;
}

StatementList parseProgram(Parser *parser) {
  StatementList prog = newStatementList();
  Statement curStatement;

  while (parser->curToken.Type != EOF_T) {
    curStatement = _parseStatement(parser);
    if (curStatement.type == NULL_STMT) {
      return prog;
    }
    appendStatementList(&prog, curStatement);
    _parserNextToken(parser);
  }

  return prog;
}

void _parserNextToken(Parser *p) {
  p->curToken = p->peekToken;
  p->peekToken = nextToken(p->l);
}

Statement _parseStatement(Parser *p) {
  switch (p->curToken.Type) {
  case LET:
    return _parseLetStatement(p);
  }
}

Statement _parseLetStatement(Parser *p) {
  LetStatement stmt;
  stmt.identifier = p->curToken;
}
