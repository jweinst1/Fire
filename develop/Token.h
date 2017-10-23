#ifndef FIRE_TOKEN_H
#define FIRE_TOKEN_H

//file that contains token structure and type

#include "TUtils.h"





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


#endif
