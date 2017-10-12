#include "Tokenizer.h"


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


void Tokenizer_Tokenize(const char* ch, char** position, Token* token)
{
        switch(*ch)
        {
        case '0':
                break;
        case '1':
                break;
        case '2':
                break;
        case '3':
                break;
        case '4':
                break;
        case '5':
                break;
        case '6':
                break;
        case '7':
                break;
        case '8':
                break;
        case '9':
                break;
        case '0':
                break;
        case '0':
                break;
        case '0':
                break;
        case '0':
                break;
        case '0':
                break;
        case '0':
                break;
        case '0':
                break;
        case '0':
                break;
        case '0':
                break;
        case '0':
                break;
        case '0':
                break;
        case '0':
                break;
        case '0':
                break;
        case '0':
                break;
        case '0':
                break;
        case '0':
                break;
        case '0':
                break;
        case '0':
                break;
        case '0':
                break;
        case '0':
                break;
        case '0':
                break;
        case '0':
                break;
        case '0':
                break;
        case '0':
                break;
        case '0':
                break;
        case '0':
                break;
        default:
                token->type = TokenType_nil;
        }
}
