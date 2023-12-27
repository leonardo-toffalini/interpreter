#include "include/parser.h"
#include "include/lexer.h"
#include "include/statement.h"
#include "include/token.h"
#include <stdbool.h>

void _parserNextToken(Parser *p);
Statement _parseStatement(Parser *p);
Statement _parseLetStatement(Parser *p);
bool _expectPeek(Parser *p, TokenType t);
bool _curTokenIs(Parser *p, TokenType t);

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
  LetStatement letStmt;
  Statement newStatement;
  newStatement.type = NULL_STMT;

  if (!_expectPeek(p, IDENT)) {
    return newStatement;
  }

  letStmt.identifier = p->curToken;

  // TODO: We're skipping the expressions until we encounter a semicolon

  while (!_curTokenIs(p, SEMICOLON)) {
    _parserNextToken(p);
  }

  newStatement.type = LET_STMT;
  newStatement.data.let = letStmt;

  return newStatement;
}

bool _curTokenIs(Parser *p, TokenType t) { return p->curToken.Type == t; }

bool _peekTokenIs(Parser *p, TokenType t) { return p->peekToken.Type == t; }

bool _expectPeek(Parser *p, TokenType t) {
  if (_peekTokenIs(p, t)) {
    _parserNextToken(p);
    return true;
  } else {
    return false;
  }
}
