#include "FirePut.h"
#include "FireStreamCore.h"
#include "ByteWrite.h"

void FirePut_put(FireStream* stream, unsigned char** code)
{
        PutParams params;
        switch (**code)
        {
        case FireType_Int:
                *code += 1;
                params.type = FireType_Int;
                params.amount = *(int*)(*code);
                *code += sizeof(int);
                params.total = sizeof(int64_t) * params.amount;
                FireStream_EXPAND_IF(stream, params.total, stream->cap);
                ByteWrite_move(stream->itemEnd, code, sizeof(int64_t), FireType_Int, params.amount);
                stream->itemEnd += params.total;
                break;
        default:
                fprintf(stderr, "ByteCode Error: Type null not recognized for put op.\n");
                exit(1);
                return;
        }
}
