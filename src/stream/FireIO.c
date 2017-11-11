#include "FireIO.h"

void FireIO_print_binary(FireStream* stream)
{
        unsigned char* ptr = stream->items;
        while(ptr != stream->itemEnd)
        {
                printf("%u", *ptr++);
        }
}
