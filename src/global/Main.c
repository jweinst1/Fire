#include <stdio.h>
#include "BytePack.h"

int main( int argc, char *argv[] )
{
        void* buffer = calloc(900, 1);
        BytePack_pack(buffer, "bbbssl", 70, 70, 50, 3000, 3000, 678532);
        for (size_t i = 0; i < 70; i++) {
                printf("%u\n", ((unsigned char*)buffer)[i]);
        }
}
