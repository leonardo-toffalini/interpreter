#ifndef AST_H
#define AST_H

#include "expression.h"
#include "token.h"

// we want something like this:
//
//
// Program
// With list of Statements
// With function: tokenLiteral() that returns the literal string of the node
//
// LetStatement
// With members:
//  - token
//  - name
//  - value
//
// With functions:
//  - tokenLiteral() that returns the literal string of the Statement
//  - statementNode()
//
//
// Identifier
// With members:
//  - token
//  - value
//
// With functions:
//  - tokenLiteral()
//  - expressionNode()
//
//

typedef struct Statement Statement;

typedef struct Program {
  Statement *Statements[];
} Program;

// typedef enum { LET_STMT, RETURN_STMT } StatementType;
//
// typedef struct LetStatement {
//   Token identifier;
//   Expression *value;
// } LetStatement;
//
// typedef union {
//   LetStatement let;
// } StatementData;
//
// typedef struct Statement {
//   StatementType type;
//   StatementData data;
// } Statement;

#endif // !AST_H
