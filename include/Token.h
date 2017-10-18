#ifndef FIRE_TOKEN_H
#define FIRE_TOKEN_H

//file that contains token structure and type

#include "TUtils.h"

#define Token_GET_NUM(tok) tok.val.number
#define Token_SET(tok, type, val) do { \
                tok.type = type; \
                tok.val = val; } while(0)

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

union TokenVal
{
        double number;
};

typedef union TokenVal TokenVal;

struct Token
{
        TokenType type;
        TokenVal val;
        int err;
};

typedef struct Token Token;

#endif
