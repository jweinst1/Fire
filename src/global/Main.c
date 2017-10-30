#include <stdio.h>
#include "FireMachine.h"

int main( int argc, char *argv[] )
{
        FireMachine fmach;
        FireMachine_MAKE_L(fmach);
        FireMachine* fmachPtr = &fmach;
        void* code = malloc(800);
        unsigned char* debug = code;
        *(unsigned char*)code = 1;
        code++;
        *(unsigned char*)code = 7;
        code++;
        double marker = 10;
        memcpy(code, &marker, sizeof(double));
        code += sizeof(double);
        *(unsigned char*)code = 1;
        code++;
        *(unsigned char*)code = 2;
        code++;
        *(unsigned char*)code = 1;
        code++;
        *(unsigned char*)code = 0;
        FireMachine_run(fmachPtr, debug);
        return 0;
}
