#include <stdio.h>
#include "FireStream.h"

int main( int argc, char *argv[] )
{
        FireStream fst;
        FireStream* fstPtr = &fst;
        FireStream_MAKE_SNUM(fstPtr, 10);
        printf(" len is then %lu\n", FireStream_LEN(fstPtr));
        FireIO_PRINT(fstPtr);
        FireReduce_SUB(fstPtr);
        FireIO_PRINT(fstPtr);
        return 0;
}
