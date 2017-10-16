#include "Exec.h"
#include <stdio.h>
#include <stdlib.h>

//if token is null, forms apply route based on current op
void Exec_apply(Executor* executor, Token* token)
{

        switch(executor->op)
        {
        case TokenType_Add:
                switch(executor->vState)
                {
                case ExecVState_Number:
                        executor->val.number += token->val.number;
                        return;
                }
                break;
        case TokenType_Sub:
                switch(executor->vState)
                {
                case ExecVState_Number:
                        executor->val.number -= token->val.number;
                        return;
                }
                break;
        case TokenType_Mul:
                switch(executor->vState)
                {
                case ExecVState_Number:
                        executor->val.number *= token->val.number;
                        return;
                }
                break;
        case TokenType_Div:
                switch(executor->vState)
                {
                case ExecVState_Number:
                        executor->val.number /= token->val.number;
                        return;
                }
                break;
        case TokenType_Out:
                switch(executor->vState)
                {
                case ExecVState_Number:
                        if(Exec_IS_INT(executor))
                                printf("%d\n", (int)(executor->val.number));
                        else printf("%f\n", executor->val.number);
                        executor->state = ExecState_AccArrow;
                        return;
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
                printf("An error has occurred, op: %d\n", executor->op);
                break;
        case ExecState_AccValue:
                switch(token->type)
                {
                case TokenType_Number:
                        executor->vState = ExecVState_Number;
                        executor->val.number = token->val.number;
                        executor->state = ExecState_AccArrow;
                        return;
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
                        return;
                default:
                        executor->state = ExecState_nil;
                        return;
                }
        case ExecState_AccOp:
                switch(token->type)
                {
                case TokenType_Add:
                case TokenType_Sub:
                case TokenType_Mul:
                case TokenType_Div:
                        executor->op = token->type;
                        executor->state = ExecState_AccArgs;
                        return;
                case TokenType_Out:
                        executor->op = token->type;
                        Exec_apply(executor, NULL);
                        return;
                default:
                        executor->state = ExecState_nil;
                        return;
                }
                break;
        case ExecState_AccArgs:
                switch(token->type)
                {
                case TokenType_ApplyNext:
                        executor->state = ExecState_AccOp;
                        return;
                default:
                        Exec_apply(executor, token);
                        return;
                }
                break;
        }
}
