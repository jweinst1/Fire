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



void Compile_repl()
{
        char codeBuf[Compile_REPL_BSIZE];
        int running = 1;
        while(running)
        {
                printf(Compile_PROMPT);
                if(fgets(codeBuf, Compile_REPL_BSIZE, stdin) != NULL)
                {
                        if(codeBuf[0] == 'e' && codeBuf[1] == 'x' && codeBuf[2] == 'i' && codeBuf[3] == 't')
                        {
                                running = 0;
                        }
                        else
                        {
                                Compile_sCompile(codeBuf);
                        }
                }
        }
}
