#include <stdio.h>
#include "Compile.h"

int main( int argc, char *argv[] )
{
        char* code = "rng 12 -> if > 3 -> out";
        Compile_compile(code);
}
