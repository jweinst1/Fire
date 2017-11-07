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
        puts("\nThe Fire Programming Language Guide");
        puts("-----------------------------------");
        puts("Fire is a reactive, stream based language, you program");
        puts("in a data flow consisting of operations and ->'s.");
        puts("@ exit: Type exit in the repl to exit the program.\n");
        puts("** Printing Data **");
        puts("-----------------------------------");
        puts("@ out: prints the current stream and it's data.");
        puts("- ex: push 5 -> push 1 -> out\n result: [5 1 ]\n");
        puts("** Adding Data **");
        puts("-----------------------------------");
        puts("@ push (number): pushes one number onto end of stream.");
        puts("- ex: push 5 -> out\n result: [5 ]");
        puts("@ rng (n): pushes a stream of numbers from zero to n onto the stream.");
        puts("- ex: rng 4 -> out\n result: [0 1 2 3 ]\n");
        puts("** Reducing Data **");
        puts("-----------------------------------");
        puts("@ {+}: Sums all the numbers in the stream and store the result at the front.");
        puts("- ex: rng 4 -> {+} -> out\n result: [6 ]");
        puts("@ {-}: Subtracts all the numbers in the stream and store the result at the front.");
        puts("- ex:");
        puts("fire> rng 4 -> out -> {-} -> out\n[0 1 2 3 ]\n[-6 ]");
        puts("@ {*}: Multiplies all the numbers in the stream and store the result at the front.");
        puts("@ {/}: Divides all the numbers in the stream and store the result at the front.\n");
        puts("** Mapping Data **");
        puts("-----------------------------------");
        puts("@ + (number): Adds some number to all numbers in the stream.");
        puts("- ex:");
        puts("fire> rng 4 -> out -> + 2 -> out\n[0 1 2 3 ]\n[2 3 4 5 ]");
        puts("@ - (number): Subtracts some number from all numbers in the stream.");
        puts("@ * (number): Multiplies each number in the stream.");
        puts("@ / (number): Divides each number in the stream.");
        puts("@ % (number): Calculates the remainder of each number of the stream by a number.");
        puts("@ floor: Calculates and maps the floor of each number in the stream");
        puts("- ex:");
        puts("fire> rng 6 -> sin -> out -> floor -> out\n[0 0.841471 0.909297 0.141120 -0.756802 -0.958924 ]\n[0 0 0 0 -1 -1 ]");
        puts("@ cos: Calculates and maps the cos of each number in the stream");
        puts("@ sin: Calculates and maps the sin of each number in the stream");
        puts("@ log: Calculates and maps the log(e) of each number in the stream");
        puts("@ exp: Calculates and maps the (e)exp power of each number in the stream\n");
        puts("** Filtering Data **");
        puts("-----------------------------------");
        puts("All filtering expressions in Fire begin with an 'if' keyword.\n Any element in the stream which holds false for the expression is removed from the string.\n");
        puts("@ if == (number): Filters out all numbers not equal to (number) in the stream.");
        puts("@ if != (number): Filters out all numbers equal to (number) in the stream.");
        puts("@ if > (number): Filters out all numbers greater than (number) in the stream.");
        puts("- ex:");
        puts("fire> rng 20 -> if > 5 -> out\n[6 7 8 9 10 11 12 13 14 15 16 17 18 19 ]");
        puts("@ if < (number): Filters out all numbers less than (number) in the stream.");

}
