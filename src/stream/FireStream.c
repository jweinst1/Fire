#include "FireStream.h"
#include "Instructions.h"


void FireStream_execute(FireStream* stream, unsigned char* code, size_t n)
{
        while(*code)
        {
                switch(*code)
                {
                case Instruction_Null:
                        return;
                        break;
                case Instruction_Print:
                        FireIO_print_stream(stream);
                        code++;
                        break;
                case Instruction_Put:
                        code++;
                        FirePut_put(stream, &code);
                        break;
                default:
                        fprintf(stderr, "ByteCode Error: Byte %u not recognized.\n", *code);
                        exit(1);
                        return;
                }
        }
}
