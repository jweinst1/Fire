#ifndef FIRE_ARITHMETIC_H
#define FIRE_ARITHMETIC_H

#include "Token.h"

//Arithmetic macros
// @note both operands must be pointers to tokens
#define Token_ADD(t1, t2) do { \
                if(t1->type == t2->type) { \
                        switch(t1->type) { \
                        case TokenType_Number: t1->val.number += t2->val.number; \
                                break; \
                        default: break; \
                        } \
                } \
                else t1->err = 1; \
} while(0)

#define Token_SUB(t1, t2) do { \
                if(t1->type == TokenType_Number && t2->type == TokenType_Number) \
                        t1->val.number -= t2->val.number; \
                else t1->err = 1; \
} while(0)

#define Token_MUL(t1, t2) do { \
                if(t1->type == TokenType_Number && t2->type == TokenType_Number) \
                        t1->val.number *= t2->val.number; \
                else t1->err = 1; \
} while(0)

#define Token_DIV(t1, t2) do { \
                if(t1->type == TokenType_Number && t2->type == TokenType_Number) \
                        t1->val.number /= t2->val.number; \
                else t1->err = 1; \
} while(0)




#endif
