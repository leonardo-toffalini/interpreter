#ifndef STATEMENT_H
#define STATEMENT_H

#include "token.h"
#include <stdio.h>

typedef struct Expression Expression;

typedef enum { LET_STMT, NULL_STMT } StatementType;

typedef struct LetStatement {
  Token identifier;
  Expression *value;
} LetStatement;

typedef union {
  LetStatement let;
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
