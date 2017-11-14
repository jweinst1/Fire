#include "ByteWrite.h"

void ByteWrite_mark(void* restrict dest, void* restrict src, size_t block, unsigned char mark, int amount)
{
        unsigned char* reader = src;
        unsigned char* writer = dest;
        size_t currBlock;
        while(amount--)
        {
                //marks data
                *writer++ = mark;
                currBlock = block;
                while(currBlock--)
                {
                        *writer++ = *reader++;
                }
        }
}
