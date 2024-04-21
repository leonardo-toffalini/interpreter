#include "include/statement.h"
#include <stdlib.h>

StatementList newStatementList() {
  StatementList newList;
  newList.capacity = 1;
  newList.statements =
      (Statement *)malloc(newList.capacity * sizeof(Statement));
  newList.count = 0;
  return newList;
}

void appendStatementList(StatementList *curList, Statement newStatement) {
  if ((curList->count) >= curList->capacity) {
    curList->statements = (Statement *)realloc(
        curList->statements, curList->capacity * 2 * sizeof(Statement));
    curList->capacity *= 2;
  }
  curList->statements[curList->count] = newStatement;
  curList->count++;
}
