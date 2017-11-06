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

void Compile_sCompile(char* source)
{
        //static state to allow for flow compilation
        static GenState compState = GenState_AccProc;
        ByteBuffer buf;
        ByteBuffer_INITL(buf);
        //static stream to keep state between calls
        static int machInit = 0;
        static FireMachine fmach;
        if(!machInit)
        {
                FireMachine_MAKE_L(fmach);
                machInit = 1;
        }
        if(!CodeGen_Generate(source, &buf, &compState))
        {
                puts("Syntax Error");
                return;
        }
        FireMachine_run(&fmach, buf.bytes);
        if(fmach.err) puts("Runtime Error");
}
