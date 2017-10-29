#include <stdio.h>
#include "FireStream.h"

int main( int argc, char *argv[] )
{
        FireStream fst;
        FireStream* fstPtr = &fst;
        FireStream_MAKE_ZRNG(fstPtr, 10);
        printf(" len is then %lu\n", FireStream_LEN(fstPtr));
        FireReduce_ADD(fstPtr);
        FireMap_PRINT(fstPtr);
        return 0;
}
