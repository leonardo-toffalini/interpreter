#include "include/token.h"
#include <string.h>

TokenType lookupIdentifier(char *identifier) {
  {
    if (strcmp(identifier, "fn") == 0) {
      return FUNCTION;
    } else if (strcmp(identifier, "let") == 0) {
      return LET;
    } else {
      return IDENT;
    }
  }
}
