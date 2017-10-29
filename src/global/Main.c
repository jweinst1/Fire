#include <stdio.h>
#include "FireStream.h"

int main( int argc, char *argv[] )
{
        FireStream fst;
        FireStream* fstPtr = &fst;
        FireStream_MAKE_ZRNG(fstPtr, 10);
        FireStream_PUSH_LNUM(fstPtr, 3);
        printf(" len is then %lu\n", FireStream_LEN(fstPtr));
        double comp = 3;
        double* compmem = &comp;
        FireFilter_GT(fstPtr, compmem);

        FireMap_PRINT(fstPtr);
        return 0;
}
