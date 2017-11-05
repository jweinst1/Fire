#include <stdio.h>
#include "CodeGen.h"
#include "FireMachine.h"

int main( int argc, char *argv[] )
{
        char* code = "push 5 -> push 3 -> {+} -> out";
        ByteBuffer buf;
        ByteBuffer_INITL(buf);
        FireMachine fmach;
        FireMachine_MAKE_L(fmach);
        CodeGen_Generate(code, &buf);
        FireMachine_run(&fmach, buf.bytes);
        for (size_t i = 0; i < 30; i++) {
                printf("%u\n", buf.bytes[i]);
        }
}
