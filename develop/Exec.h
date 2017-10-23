#ifndef FIRE_EXEC_H
#define FIRE_EXEC_H

#include "Token.h"
#include <math.h>

//configures an executor for default settings
#define Exec_DEFAULT(name) do { \
                name.state = ExecState_AccValue; \
                name.skipCount = 0; } while(0)

#define Exec_SET_NUM(exc, num) do { \
                exc->vState = ExecVState_Number; \
                exc->val.number = num;} while(0)

#define Exec_IS_INT(exc) (exc->token.val.number - floor(exc->token.val.number) == 0.0)

//checks if executor has an error
#define Exec_HAS_ERR(exc) (exc->token.err)

#define Exec_SET_ERR(exc, opt) exc->token.err = opt

//error handling done by setting tokentype to nil.
enum ExecState
{
        ExecState_AccValue,
        ExecState_AccArrow,
        ExecState_AccOp,
        ExecState_AccArgs
};

typedef enum ExecState ExecState;

//stores the value the executor works on.
//may need struct-based polymorphic approach in future
//uses token val union to be consistent with incoming tokens.
typedef union TokenVal ExecValue;

struct Executor
{
        Token token;
        ExecState state;
        TokenType op;
        int skipCount; //used for control tokens
};

typedef struct Executor Executor;

static inline void
Exec_ErrReset(Executor* executor)
{
        executor->state = ExecState_AccValue;
        executor->skipCount = 0;
        executor->token.type = TokenType_nil;
        executor->token.err = 0;
        executor->op = TokenType_nil;
}

//function that applies an argument to a an executor/machine with an op and value
void Exec_apply(Executor* executor, Token* token);

//main function to apply new tokens to an executor
void Exec_execute(Executor* executor, Token* token);

#endif
