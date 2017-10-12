#ifndef FIRE_ENUMTYPES_HEAD
#define FIRE_ENUMTYPES_HEAD

enum TokenType
{
        TokenType_Operation,
        TokenType_Number,
        TokenType_Argbegin,
        TokenType_Argend
};

enum FireOp
{
        FireOp_nil,
        FireOp_Add
};

enum TokzState
{
        TokzState_Base,
        TokzState_Comment
};

#endif
