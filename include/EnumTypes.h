#ifndef FIRE_ENUMTYPES_HEAD
#define FIRE_ENUMTYPES_HEAD

typedef enum TokenType
{
        TokenType_Operation,
        TokenType_Number,
        TokenType_Argbegin,
        TokenType_Argend
} TokenType;

typedef enum FireOp
{
        FireOp_nil,
        FireOp_Add
} FireOp;

typedef enum TokzState
{
        TokzState_Base,
        TokzState_Comment
} TokzState;

#endif
