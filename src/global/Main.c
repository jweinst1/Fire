#include <stdio.h>
#include <string.h>
#include "FireStream.h"

int main( int argc, char *argv[] )
{
        FireStream fst;
        FireStream_make(&fst);


        unsigned char code[] = {1, 2, 1, 2, 0, 0, 0, 55, 0, 0, 0, 0, 0, 0, 0, 55, 0, 0, 0, 0, 0, 0, 0, 1, 0};

        FireStream_execute(&fst, code, 3);
}
