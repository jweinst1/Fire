#include <stdio.h>
#include "FireMachine.h"
#include "CodeGen.h"

int main( int argc, char *argv[] )
{
        FireMachine fmach;
        FireMachine_MAKE_L(fmach);
        FireStream* fst = &fmach.stream;
        FireStream_SET_RNG(fst, 6, 66);
        FireIO_PRINT(fst);
        return 0;
}
