#include "Tokenizer.h"
#include <stdlib.h>


int isOpChar(char ch)
{
        switch(ch)
        {
        case '+': return 1;
        case '-': return 1;
        case '*': return 1;
        case '/': return 1;
        case '%': return 1;
        case '!': return 1;
        case '&': return 1;
        case '>': return 1;
        case '=': return 1;
        case '<': return 1;
        case '?': return 1;
        default:  return 0;
        }
}


void Tokenizer_Tokenize(char* ch, char** position, Token* token)
{
        while(isspace(*ch)) ch++;
        switch(*ch)
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
                token->val.number = strtod(ch, position);
                token->type = TokenType_Number;
                break;
        case '-':
                if(isdigit(ch[1]))
                {
                        token->val.number = strtod(ch, position);
                        token->type = TokenType_Number;
                }
                else if(ch[1] == '>')
                {
                        token->type = TokenType_ApplyNext;
                        *position = ch + 2;
                }
                else
                {
                        token->type = TokenType_Sub;
                        *position = ch + 1;
                }
                break;
        case '+':
                token->type = TokenType_Add;
                *position = ch + 1;
                break;
        case '*':
                token->type = TokenType_Mul;
                *position = ch + 1;
                break;
        case '/':
                token->type = TokenType_Div;
                *position = ch + 1;
                break;
        case 'o':
                switch(ch[1])
                {
                case 'u':
                        switch(ch[2])
                        {
                        case 't':
                                token->type = TokenType_Out;
                                *position = ch + 3;
                                return;
                        default:
                                break;
                        }
                        break;
                default:
                        break;
                }
                break;
        default:
                token->type = TokenType_nil;
                *position = ch + 1;
        }
}
