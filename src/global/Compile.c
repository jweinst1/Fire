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

void Compile_help()
{
        puts("The Fire Programming Language Guide");
        puts("-----------------------------------");
        puts("Fire is a reactive, stream based language, you program");
        puts("in a data flow consisting of operations and ->'s.\n");
        puts("** Printing Data **");
        puts("@ out: prints the current stream and it's data.");
        puts("- ex: push 5 -> push 1 -> out\n result: [5 1 ]\n");
        puts("** Adding Data **");
        puts("@ push (number): pushes one number onto end of stream.");
        puts("- ex: push 5 -> out\n result: [5 ]");
        puts("@ rng (n): pushes a stream of numbers from zero to n onto the stream.");
        puts("- ex: rng 4 -> out\n result: [0 1 2 3 ]\n");
        puts("** Reducing Data **");
        puts("@ {+}: Sums all the numbers in the stream and store the result at the front.");
        puts("- ex: rng 4 -> {+} -> out\n result: [6 ]");
        puts("@ {-}: Subtracts all the numbers in the stream and store the result at the front.");
        puts("- ex:");
        puts("fire> rng 4 -> out -> {-} -> out\n[0 1 2 3 ]\n[-6 ]");
        puts("@ {*}: Multiplies all the numbers in the stream and store the result at the front.");
        puts("@ {/}: Divides all the numbers in the stream and store the result at the front.");
}
