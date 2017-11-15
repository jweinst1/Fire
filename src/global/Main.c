#include <stdio.h>
#include <string.h>
#include "FireStream.h"

int main( int argc, char *argv[] )
{
        unsigned char code[] = {1, 2, 1, 2, 0, 0, 0, 88, 0, 0, 0, 0, 0, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 1, 0};
        unsigned char* codepnt = code;
        FireStream_MAKE(test, 2000);
        FireStream_execute(&test, codepnt);
}
