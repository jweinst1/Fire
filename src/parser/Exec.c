#include "Exec.h"
#include <stdio.h>

void Exec_apply(Executor* executor, Token* token)
{
        switch(token->type)
        {
        case TokenType_Number:
                switch(executor->op)
                {
                case TokenType_Add:
                        executor->val.number += token->val.number;
                        break;
                case TokenType_Sub:
                        executor->val.number -= token->val.number;
                        break;
                }
                break;

        default:
                executor->state = ExecState_nil;
        }

}

void Exec_execute(Executor* executor, Token* token)
{
        switch(executor->state)
        {
        case ExecState_nil:
                printf("An error has occurred, state: %d", executor->state);
                break;
        case ExecState_AccValue:
                switch(token->type)
                {
                case TokenType_Number:
                        executor->vState = ExecVState_Number;
                        exc->val.number = token->val.number;
                        executor->state = ExecState_AccArrow;
                        break;
                default:
                        executor->state = ExecState_nil;
                        return;
                }
                break;
        case ExecState_AccArrow:
                switch(token->type)
                {
                case TokenType_ApplyNext:
                        executor->state = ExecState_AccOp;
                        break;
                default:
                        executor->state = ExecState_nil;
                        return;
                }
        case ExecState_AccOp:
                switch(token->type)
                {
                case TokenType_Add:
                case TokenType_Sub:
                case TokenType_Out:
                        executor->op = token->type;
                        executor->state = ExecState_AccArgs;
                        break;
                default:
                        executor->state = ExecState_nil;
                        return;
                }
                break;
        case ExecState_AccArgs:
                Exec_apply(executor, token);
                break;
        }
}
