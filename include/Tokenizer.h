#ifndef FIRE_TOKENIZER_H
#define FIRE_TOKENIZER_H

#include "ctype.h"

#include "EnumTypes.h"


#define Tokenizer_NAME_START(ch) (isalpha(ch) || ch == '_')

static inline int
isNameStart(char ch)
{
        return isalpha(ch) || ch == '_';
}

FireOp Tokenizer_detOp(const char* ch);

void Tokenizer_Tokenize(const char* ch);



#endif
