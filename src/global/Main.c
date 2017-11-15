#include <stdio.h>
#include <string.h>
#include "FireStreamCore.h"

int main( int argc, char *argv[] )
{
        FireStream_MAKE(foo, 5000)

        printf("The cap is %lu\n", foo.cap);
}
