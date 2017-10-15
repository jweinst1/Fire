#include <stdio.h>
#include "Compile.h"

int main( int argc, char *argv[] )
{
        char* code = "6 -> + 4 -> out";
        Compile_compile(code);

        return 0;
}
