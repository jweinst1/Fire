#ifndef FIRE_TUTILS_H
#define FIRE_TUTILS_H
//contains util macros for tokens


#define Token_COPY_TO(t1, t2) do { \
                switch(t1->type) { \
                case TokenType_Number: \
                        t2->type = TokenType_Number; \
                        t2->val.number = t1->val.number; \
                        break; \
                default: \
                        t2->type = t1->type; \
                        break; \
                } \
} while(0)

#endif
