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
        FireStream_PUT(fstream, 66);
        printf("The length is %lu\n", fstream->itemEnd - fstream->items);
        printf("The last is %u\n", *(unsigned char*)(fstream->itemEnd-1));
        return 0;
}
