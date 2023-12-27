#ifndef STATEMENT_H
#define STATEMENT_H

#include "token.h"
#include <cstddef>

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
  size_t data;
} StatementList;

StatementList newStatementList();
void appendStatementList(StatementList *curList, Statement newStatement);

#endif // !STATEMENT_H
