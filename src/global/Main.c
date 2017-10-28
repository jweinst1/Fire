#include <stdio.h>
#include "FireStream.h"

int main( int argc, char *argv[] )
{
        FireStream fst;
        FireStream* fstPtr = &fst;
        FireStream_MAKE(fstPtr, 1000);
        double end = 7;
        double* endp = &end;
        FireStream_PUSH_ZRNG(fstPtr, endp);
        printf("%ld\n", FireStream_LEN(fstPtr));
        FireMap_ADD(fstPtr, 300);
        printf("%f\n", *(double*)(fstPtr->items + 1));
        printf("%f\n", *(double*)(fstPtr->items + 10));
        return 0;
}
