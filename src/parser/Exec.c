#include "Exec.h"

void Exec_execute(Executor* executor, Token* token)
{
        switch(executor->state)
        {
        case ExecState_nil:
                break;
        case ExecState_AccValue:
                switch(token->type)
                {
                case TokenType_Number:
                        break;
                default:
                        break;
                }
                break;
        case ExecState_AccOp:
                switch(token->type)
                {
                default:
                        break;
                }
                break;
        case ExecState_AccArgs:
                switch(token->type)
                {
                default:
                        break;
                }
                break;
        }
}
