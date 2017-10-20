#ifndef FIRE_TOKEN_H
#define FIRE_TOKEN_H

//file that contains token structure and type

#include <stdlib.h>
#include "TUtils.h"

#define Token_DEFAULT_SIZE 200
#define Token_EXPAND_BUF(tok) tok->buf = realloc(tok->buf, (tok->capacity*= 2));





enum TokenType
{
        TokenType_nil,
        TokenType_Self,
        TokenType_Add,
        TokenType_Sub,
        TokenType_Mul,
        TokenType_Div,
        TokenType_Number,
        TokenType_ApplyNext,
        TokenType_Out
};

typedef enum TokenType TokenType;

struct Token
{
        TokenType type;
        void* buf;
        size_t cap;
        size_t len;
        int err;
};

typedef struct Token Token;

static inline void
Token_initBuf(Token* token)
{
        token->buf = malloc(Token_DEFAULT_SIZE);
        token->cap = Token_DEFAULT_SIZE;
        token->len = 0;
}

#endif
