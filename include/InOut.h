#ifndef FIRE_INOUT_H
#define FIRE_INOUT_H
//input output macros


#include <stdio.h>

#define Token_PRINT(tok) do { \
                switch(tok->type) { \
                case TokenType_Number:  \
                        printf("foo"); \
                        break; \
                } \
} while(0)

#endif
