#include <stdio.h>
#include <string.h>
#include "FireStream.h"

int main( int argc, char *argv[] )
{
        FireStream fst;
        FireStream_make(&fst);
        FireStream_write_fmt(&fst, "blbl", 1, 300, 1, 300);
        FireIO_print_binary_lines(&fst);
        FireIO_print_stream(&fst);
}
