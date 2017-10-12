#ifndef FIRE_TOKENIZER_H
#define FIRE_TOKENIZER_H

#include "ctype.h"
#include "Token.h"
#include "EnumTypes.h"

#define Tokenizer_NAME_START(ch) (isalpha(ch) || ch == '_')


static inline int
isNameStart(char ch)
{
        return isalpha(ch) || ch == '_' || ch == '$';
}

int isOpChar(char ch);

void Tokenizer_Tokenize(const char* ch, char** position, Token* token);



#endif
