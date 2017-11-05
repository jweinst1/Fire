#include <stdio.h>
#include "BytePack.h"

int main( int argc, char *argv[] )
{
        unsigned char* buffer = calloc(901, 1);
        BytePack_bpack(&buffer, "l", 678532);
        for (size_t i = 0; i < 10; i++) {
                printf("%u\n", ((unsigned char*)buffer)[i]);
        }
        size_t f = 0;
        BytePack_len("bbbsi", &f);
        printf("%lu\n", f);
}
