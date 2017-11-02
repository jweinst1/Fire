#include "CodeGen.h"


void CodeGen_GetStart(char* srcCode, ByteBuffer* buffer)
{
        switch(*srcCode)
        {
        case '[':
                srcCode++;
                //stream lit method
                break;
        default:
                //error handling
                break;
        }
}

void CodeGen_Generate(char* srcCode, ByteBuffer* buffer)
{
        CodeGen_ADV_WS(srcCode);
        while(*srcCode)
        {
                /*switch(*srcCode)
                   {

                   }*/
                break;
        }
}
