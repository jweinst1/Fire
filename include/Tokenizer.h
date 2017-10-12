#ifndef FIRE_TOKENIZER_H
#define FIRE_TOKENIZER_H

#include "ctype.h"

#define Tokenizer_NAME_START(ch) (isalpha(ch) || ch == '_')

static inline int
isNameStart(char ch)
{
        return isalpha(ch) || ch == '_';
}

#endif
