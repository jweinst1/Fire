#include "GenReduce.h"

int GenReduce_gen(char** srcCode, ByteBuffer* bbuf)
{
        switch(**srcCode)
        {
        case '}':
                *srcCode += 1;
                return 1;
        case '+':
                ByteBuffer_WRITE(bbuf, Instruction_Reduce_Add);
                if((*srcCode)[1] != '}') return 0; // error
                srcCode += 2;
                return 1;
        case '-':
                ByteBuffer_WRITE(bbuf, Instruction_Reduce_Sub);
                if((*srcCode)[1] != '}') return 0; // error
                srcCode += 2;
                return 1;
        case '*':
                ByteBuffer_WRITE(bbuf, Instruction_Reduce_Mul);
                if((*srcCode)[1] != '}') return 0; // error
                srcCode += 2;
                return 1;
        case '/':
                ByteBuffer_WRITE(bbuf, Instruction_Reduce_Div);
                if((*srcCode)[1] != '}') return 0; // error
                srcCode += 2;
                return 1;
        default:
                return 0;
        }
}
