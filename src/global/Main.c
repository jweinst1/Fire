#include <stdio.h>
#include "FireStream.h"

int main( int argc, char *argv[] )
{
        FireStream fst;
        FireStream* fstPtr = &fst;
        FireStream_MAKE(fstPtr, 1000);
        double num = 777;
        void* nPtr = &num;
        FireStream_PUSH_NUM(fstPtr, nPtr);
        printf("%ld\n", FireStream_LEN(fstPtr));
        return 0;
}
