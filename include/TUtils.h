#ifndef FIRE_TUTILS_H
#define FIRE_TUTILS_H
//contains util macros for tokens

#include "Token.h"

#define Token_COPY_FROM(t1, t2) do { \
                switch(t2->type) { \
                case TokenType_Number: \
                        break; \
                case TokenType_Add: \
                        break; \
                } \
} while(0)

#endif
