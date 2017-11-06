#include <stdio.h>
#include <string.h>
#include "Compile.h"

int main( int argc, char *argv[] )
{
        if(argc == 2)
        {
                if(!strcmp("-i", argv[1])) Compile_repl();
        }
}
