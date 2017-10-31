#include <stdio.h>
#include "FireMachine.h"
#include "CodeGen.h"

int main( int argc, char *argv[] )
{
        char* mes = "  rrr   ->  fff";
        CodeGen_PRS_AR(mes);
        puts(mes);
        return 0;
}
