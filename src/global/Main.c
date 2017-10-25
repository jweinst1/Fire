#include <stdio.h>
#include "FireMachine.h"

int main( int argc, char *argv[] )
{
        FireMachine mach;
        FireMachine_MAKE_L(mach);
        double g = 6700;
        unsigned char bytes[10];
        bytes[0] = 1;
        bytes[9] = 0;
        memcpy(bytes + 1, &g,sizeof(double));
        FireMachine_run(&mach, bytes);
        FireStream* fstream = &mach.stream;
        FireMap_ADD(fstream, 55);
        FireMap_PRINT(fstream);
        return 0;
}
