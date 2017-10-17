#ifndef FIRE_ARITHMETIC_H
#define FIRE_ARITHMETIC_H

#define Token_ADD(t1, t2) do { \
                if(t1->type == t2->type) { \
                        switch(t1->type) { \
                        case TokenType_Number: t1->val.number += t2->val.number; \
                                break; \
                        default: break; \
                        } \
                } \
} while(0)

#endif
