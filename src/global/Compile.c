#include <stdio.h>
#include "Compile.h"

void Compile_compile(char* source)
{
        GenState compState = GenState_AccProc;
        ByteBuffer buf;
        ByteBuffer_INITL(buf);
        FireMachine fmach;
        FireMachine_MAKE_L(fmach);
        if(!CodeGen_Generate(source, &buf, &compState))
        {
                puts("Syntax Error");
                return;
        }
        FireMachine_run(&fmach, buf.bytes);
        if(fmach.err) puts("Runtime Error");
}
