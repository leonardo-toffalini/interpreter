#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "statement.h"
#include "token.h"
#include <stdbool.h>

typedef struct Expression Expression;

typedef struct InfixExpr {
  Token op;
  Expression *left;
  Expression *right;
} InfixExpr;

struct prefixExpr {
  Token op;
  Expression *right;
};

struct ifExpr {
  Expression *condition;
  StatementList consequence;
  bool hasAlternative;
  StatementList alternative;
};

typedef enum {
  INFIX_EXPR,
  PREFIX_EXPR,
  LITERAL_EXPR,
  IF_EXPR,
  CALL_EXPR
} ExpressionType;

typedef union {
  struct InfixExpr inf;
  struct prefixExpr pre;
  struct ifExpr ifelse;
} ExpressionData;

typedef struct Expression {
  ExpressionType type;
  ExpressionData data;
} Expression;

#endif // !EXPRESSION_H
