#include <stdio.h>
#include "CodeGen.h"
#include "FireMachine.h"

int main( int argc, char *argv[] )
{
        char* code = "rng 12 -> + 3 -> out";
        ByteBuffer buf;
        ByteBuffer_INITL(buf);
        FireMachine fmach;
        FireMachine_MAKE_L(fmach);
        GenState stat = GenState_AccProc;
        CodeGen_Generate(code, &buf, &stat);

        FireMachine_run(&fmach, buf.bytes);
        for (size_t i = 0; i < 30; i++) {
                printf("%u\n", buf.bytes[i]);
        }
}
