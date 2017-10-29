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
        FireFilter_LT(fstPtr, compmem);
        printf(" len is now %lu, val is %f\n", FireStream_LEN(fstPtr), *(double*)(fstPtr->items + 1));
        return 0;
}
