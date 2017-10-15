#ifndef FIRE_EXEC_H
#define FIRE_EXEC_H

#include "Token.h"

//configures an executor for default settings
#define Exec_DEFAULT(name) do { \
                name.state = ExecState_AccValue; } while(0)

#define Exec_SET_NUM(exc, num) do { \
                exc->vState = ExecVState_Number; \
                exc->val.number = num;} while(0)

//error handling done by setting state to nil, triggering error on next token.
enum ExecState
{
        ExecState_nil, //0 state for errors
        ExecState_AccValue,
        ExecState_AccArrow,
        ExecState_AccOp,
        ExecState_AccArgs
};

typedef enum ExecState ExecState;

//enum needed to keep track of what kind of value the executor holds
enum ExecVState
{
        ExecVState_Number
};

typedef enum ExecVState ExecVState;

//stores the value the executor works on.
//may need struct-based polymorphic approach in future
union ExecValue
{
        double number;
};

typedef union ExecValue ExecValue;

struct Executor
{
        ExecValue val;
        ExecVState vState;
        ExecState state;
        TokenType op;
};

typedef struct Executor Executor;

//function that applies an argument to a an executor/machine with an op and value
void Exec_apply(Executor* executor, Token* token);

//main function to apply new tokens to an executor
void Exec_execute(Executor* executor, Token* token);

#endif
