#ifndef FIRE_INOUT_H
#define FIRE_INOUT_H
//input output macros


#include <stdio.h>
#include <math.h>

//print without newline
#define Token_PRINT(tok) do { \
                switch(tok->type) { \
                case TokenType_Number:  \
                        if(tok->val.number - floor(tok->val.number) == 0.0) printf("%d", (int)(tok->val.number)); \
                        else printf("%f", tok->val.number); \
                        break; \
                default: \
                        printf("%s", "token"); \
                } \
} while(0)

//prints always with a newline
#define Token_PRINTN(tok) do { \
                switch(tok->type) { \
                case TokenType_Number:  \
                        if(tok->val.number - floor(tok->val.number) == 0.0) printf("%d\n", (int)(tok->val.number)); \
                        else printf("%f\n", tok->val.number); \
                        break; \
                default: \
                        puts("token"); \
                } \
} while(0)

#endif
