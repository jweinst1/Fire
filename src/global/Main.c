#include <stdio.h>
#include "Compile.h"

int main( int argc, char *argv[] )
{
        char* code = "6 -> + 4 -> / 5 -> out -> + 1 2 -> out";
        Compile_compile(code);

        return 0;
}
