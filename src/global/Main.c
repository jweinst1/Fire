#include <stdio.h>
#include "FireStream.h"

int main( int argc, char *argv[] )
{
        FireStream sm;
        FireStream* smPtr = &sm;
        FireStream_MAKE(smPtr, 10);

        int nums[2];
        nums[0] = 3;
        nums[1] = 55;
        FireStream_WRITE_N(smPtr, nums, 8);
        FireStream_WRITE_N(smPtr, nums, 8);
        FireStream_WRITE_N(smPtr, nums, 8);
        int* nmLst = smPtr->items;
        printf("First and second is %d and %d\n", nmLst[2], nmLst[3]);

        FireStream second;
        FireStream* secondPtr = &second;
        FireStream_COPY(secondPtr, smPtr);
        nmLst = secondPtr->items;
        printf("First and second is %d and %d\n", nmLst[2], nmLst[3]);
        FireStream_CLEAR(secondPtr);
        printf("First and len is %d and %ld\n", nmLst[2], secondPtr->len);
        return 0;
}
