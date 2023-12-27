#include "include/ast.h"

char *tokenLiteral(Program *p) {
  int len = sizeof(p->statements) / sizeof(Statement);
  if (len > 0) {
    return tokenLiteral(p->statements[0]);
  }
}
