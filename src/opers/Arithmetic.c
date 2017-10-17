#include "Arithmetic.h"

void Token_add(Token* t1, Token* t2)
{
        switch(t1->type)
        {
        case TokenType_Number:
                switch(t2->type)
                {
                case TokenType_Number:
                        t1->val.number += t2->val.number;
                        return;
                }
                break;
        }
}
