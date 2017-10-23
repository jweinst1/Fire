#include <stdio.h>
#include "FireStream.h"

int main( int argc, char *argv[] )
{
        FireStream sm;
        FireStream* smPtr = &sm;
        FireStream_MAKE(smPtr, 800);

        int nums[2];
        nums[0] = 3;
        nums[1] = 55;
        FireStream_WRITE_N(smPtr, nums, 8);
        int* nmLst = smPtr->items;
        printf("First and second is %d and %d\n", nmLst[0], nmLst[1]);
        return 0;
}
