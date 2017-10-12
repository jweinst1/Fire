#include "Tokenizer.h"

static TokzState Tokenizer_STATE = TokzState_Base;

void Tokenizer_setState(TokzState state)
{
        Tokenizer_STATE = state;
}
TokzState Tokenizer_getState()
{
        return Tokenizer_STATE;
}

FireOp Tokenizer_detOp(const char* ch)
{
        switch(*ch)
        {
        default:
                return FireOp_nil;
        }
}

void Tokenizer_Tokenize(const char* ch)
{
        while(*ch)
        {
                switch(Tokenizer_STATE)
                {
                case TokzState_Base:
                        if(*ch == '#')
                        {
                                Tokenizer_STATE = TokzState_Comment;
                                ch++;
                        }
                        break;
                case TokzState_Comment:
                        if(*ch == '\n')
                        {
                                Tokenizer_STATE = TokzState_Base;
                                ch++;
                        }
                        break;
                }
        }
}
