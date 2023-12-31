#ifndef AST_H
#define AST_H

#include "expression.h"
#include "token.h"

typedef enum {
  LOWEST_PRIO,
  EQUALS_PRIO,
  LESSGREATER_PRIO,
  SUM_PRIO,
  PRODUCT_PRIO,
  PREFIX_PRIO,
  CALL_PRIO
} Precedence;

#endif // !AST_H
