#include "include/parser.h"
#include "include/lexer.h"
#include "include/statement.h"
#include "include/token.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void _parserNextToken(Parser *p);
Statement _parseStatement(Parser *p);
Statement _parseLetStatement(Parser *p);
Statement _parseReturnStatement(Parser *p);
bool _expectPeek(Parser *p, TokenType t);
bool _curTokenIs(Parser *p, TokenType t);
void _peekError(Parser *p, TokenType t);

Parser initParser(Lexer *l) {
  Parser p;

  p.l = l;
  p.numErrors = 0;

  _parserNextToken(&p);
  _parserNextToken(&p);

  return p;
}

StatementList parseProgram(Parser *p) {
  StatementList prog = newStatementList();
  Statement curStatement;

  while (!_curTokenIs(p, EOF_T)) {
    curStatement = _parseStatement(p);
    if (curStatement.type == NULL_STMT) {
      return prog;
    }
    appendStatementList(&prog, curStatement);
    _parserNextToken(p);
  }

  return prog;
}

bool checkParserErrors(Parser *p) {
  if (p->numErrors == 0)
    return true;

  printf("Parser has %d errors:\n", p->numErrors);
  for (int i = 0; i < p->numErrors; i++) {
    printf("\tError: %s\n", p->errors[i]);
  }
  return false;
}

void _parserNextToken(Parser *p) {
  p->curToken = p->peekToken;
  p->peekToken = nextToken(p->l);
}

Statement _parseStatement(Parser *p) {
  Statement null;
  null.type = NULL_STMT;

  switch (p->curToken.Type) {
  case LET:
    return _parseLetStatement(p);
  case RETURN:
    return _parseReturnStatement(p);
  default:
    return null;
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

  if (!_expectPeek(p, ASSIGN)) {
    return newStatement;
  }

  // TODO: We're skipping the expressions until we encounter a semicolon

  while (!_curTokenIs(p, SEMICOLON)) {
    _parserNextToken(p);
  }

  newStatement.type = LET_STMT;
  newStatement.data.let = letStmt;

  return newStatement;
}

Statement _parseReturnStatement(Parser *p) {
  ReturnStatement retStmt;
  Statement newStatement;
  newStatement.type = NULL_STMT;

  _parserNextToken(p);

  // TODO: We're skipping the expressions until we encounter a semicolon

  while (!_curTokenIs(p, SEMICOLON)) {
    _parserNextToken(p);
  }

  newStatement.type = RETURN_STMT;
  newStatement.data.ret = retStmt;
  return newStatement;
}

bool _curTokenIs(Parser *p, TokenType t) { return p->curToken.Type == t; }

bool _peekTokenIs(Parser *p, TokenType t) { return p->peekToken.Type == t; }

bool _expectPeek(Parser *p, TokenType t) {
  if (_peekTokenIs(p, t)) {
    _parserNextToken(p);
    return true;
  } else {
    _peekError(p, t);
    return false;
  }
}

void _peekError(Parser *p, TokenType t) {
  char *expextedTokenString = tokenToString(t);
  char *actualTokenString = tokenToString(p->peekToken.Type);

  sprintf(p->errors[p->numErrors],
          "Expected next token to be %s but got %s instead.\n",
          expextedTokenString, actualTokenString);

  free(expextedTokenString);
  free(actualTokenString);
  p->numErrors++;
}
