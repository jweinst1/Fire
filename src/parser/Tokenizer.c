#include "Tokenizer.h"

static TokzState Tokenizer_STATE = TokzState_Base;

void Tokenizer_setState(TokzState state)
{

}
TokzState Tokenizer_getState()
{

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
                                state = TokzState_Comment;
                                ch++;
                        }
                        break;
                case TokzState_Comment:
                        if(*ch == '\n')
                        {
                                state = TokzState_Base;
                                ch++;
                        }
                        break;
                }
        }
}
