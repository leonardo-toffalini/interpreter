#ifndef STATEMENT_H
#define STATEMENT_H

#include "token.h"
#include <stdio.h>

typedef struct Expression Expression;

typedef enum { LET_STMT, RETURN_STMT, EXPR_STMT, NULL_STMT } StatementType;

typedef struct LetStatement {
  Token identifier;
  Expression *value;
} LetStatement;

typedef struct ReturnStatement {
  Expression *returnValue;
} ReturnStatement;

typedef struct ExpressionStatement {
  Expression *expressionValue;
} ExpressionStatement;

typedef union {
  LetStatement let;
  ReturnStatement ret;
  ExpressionStatement expr;
} StatementData;

typedef struct Statement {
  StatementType type;
  StatementData data;
} Statement;

typedef struct StatementList {
  Statement *statements;
  size_t count;
  size_t capacity;
} StatementList;

StatementList newStatementList();
void appendStatementList(StatementList *curList, Statement newStatement);

#endif // !STATEMENT_H
