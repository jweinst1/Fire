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
        unsigned char* iter = fstPtr->items;
        for(; iter != fstPtr->itemEnd; iter++) printf("%u, \n", *iter);
        return 0;
}
