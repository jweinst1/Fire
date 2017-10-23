#include "Exec.h"
#include <stdio.h>
#include <stdlib.h>

#include "Arithmetic.h"
#include "InOut.h"

//if token is null, forms apply route based on current op
void Exec_apply(Executor* executor, Token* token)
{
        Token* eToken = &executor->token;
        switch(executor->op)
        {
        case TokenType_Add:
                Token_ADD(eToken, token);
                break;
        case TokenType_Sub:
                Token_SUB(eToken, token);
                break;
        case TokenType_Mul:
                Token_MUL(eToken, token);
                break;
        case TokenType_Div:
                Token_DIV(eToken, token);
                break;
        case TokenType_Out:
                Token_PRINTN(eToken);
                break;

        default:
                Exec_SET_ERR(executor, 1);
        }

}

void Exec_execute(Executor* executor, Token* token)
{
        Token* eToken = &executor->token;
        if(token->err == 1)
        {

                printf("An error has occurred, op: %d\n", executor->op);
                Exec_ErrReset(executor);
                return;
        }
        switch(executor->state)
        {
        case ExecState_AccValue:
                switch(token->type)
                {
                case TokenType_Number:
                        executor->token.type = TokenType_Number;
                        executor->token.val.number = token->val.number;
                        executor->state = ExecState_AccArrow;
                        return;
                default:
                        Exec_SET_ERR(executor, 1);
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
                        Exec_SET_ERR(executor, 1);
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
                        Exec_SET_ERR(executor, 1);
                        return;
                }
                break;
        case ExecState_AccArgs:
                switch(token->type)
                {
                case TokenType_ApplyNext:
                        executor->state = ExecState_AccOp;
                        return;
                case TokenType_Self:
                        Token_COPY_TO(eToken, token);
                        Exec_apply(executor, token);
                        return;
                default:
                        Exec_apply(executor, token);
                        return;
                }
                break;
        }
}
