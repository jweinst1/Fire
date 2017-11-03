#include <stdio.h>
#include "GenStream.h"

int main( int argc, char *argv[] )
{
        char * g = "rng 77]";
        ByteBuffer bbuffer;
        ByteBuffer_INITL(bbuffer);
        GenStream_gen(&g, &bbuffer);
        for (size_t i = 0; i < 15; i++) {
                printf("%u\n", bbuffer.bytes[i]);
        }
        double* dbpnt = (double*)(bbuffer.bytes + 1);
        printf("%f\n", *dbpnt);
}
