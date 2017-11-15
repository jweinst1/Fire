#include "FirePut.h"
#include "FireStreamCore.h"

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
                params.total = sizeof(long) * params.amount;
                long* numptr = (void*)(*code);
                /*while(params.amount--)
                   {
                        FireStream_int_push(stream, *numptr++);
                   }*/
                *code += params.total;
                //printf("type is %d, amount is %d, total is %lu\n", params.type, params.amount, params.total);
                break;
        default:
                fprintf(stderr, "ByteCode Error: Type null not recognized for put op.\n");
                exit(1);
                return;
        }
}
