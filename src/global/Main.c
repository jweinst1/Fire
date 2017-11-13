#include <stdio.h>
#include <string.h>
#include "FireStream.h"

int main( int argc, char *argv[] )
{
        FireStream fst;
        FireStream_make(&fst);
        unsigned char code[] = {0, 1, 1};
        FireStream_execute(&fst, code, 3);
}
