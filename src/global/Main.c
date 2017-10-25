#include <stdio.h>
#include "FireMachine.h"

int main( int argc, char *argv[] )
{
        FireMachine mach;
        FireMachine_MAKE_L(mach);
        unsigned char bytes[] = {1, 155, 1, 0, 0, 155, 1, 0, 0, 0};
        FireMachine_run(&mach, bytes);
        FireStream* fstream = &mach.stream;
        FireMap_PRINT(fstream);
        return 0;
}
