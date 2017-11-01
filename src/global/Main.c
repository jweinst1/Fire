#include <stdio.h>
#include "FireMachine.h"
#include "CodeGen.h"

int main( int argc, char *argv[] )
{
        char * g = "      [] -> puts";
        CodeGen_ADV_WS(g);
        puts(g);
        return 0;
}
