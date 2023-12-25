#include "include/token.h"
#include <string.h>

TokenType lookupIdentifier(char *identifier) {
  {
    if (strcmp(identifier, "fn") == 0) {
      return FUNCTION;
    } else if (strcmp(identifier, "let") == 0) {
      return LET;
    } else if (strcmp(identifier, "true") == 0) {
      return TRUE;
    } else if (strcmp(identifier, "false") == 0) {
      return FALSE;
    } else if (strcmp(identifier, "if") == 0) {
      return IF;
    } else if (strcmp(identifier, "else") == 0) {
      return ELSE;
    } else if (strcmp(identifier, "return") == 0) {
      return RETURN;
    } else {
      return IDENT;
    }
  }
}
