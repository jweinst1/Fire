#include <stdio.h>
#include "Compile.h"

int main( int argc, char *argv[] )
{
        //compiles first argument of a quote for fire
        Compile_compile(argv[1]);
        return 0;
}
