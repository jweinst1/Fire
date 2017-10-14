#ifndef FIRE_EXEC_H
#define FIRE_EXEC_H

#include "Token.h"

//error handling done by setting state to nil, triggering error on next token.

enum ExecState
{
        ExecState_nil, //0 state for errors
        ExecState_AccValue,
        ExecState_AccOp,
        ExecState_AccArgs
};

typedef enum ExecState ExecState;

//enum needed to keep track of what kind of value the executor holds
enum ExecVState
{

};

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
};

typedef struct Executor Executor;

void Exec_execute(Executor* executor, Token* token);

#endif
