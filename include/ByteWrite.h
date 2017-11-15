#ifndef BYTE_WRITE_H
#define BYTE_WRITE_H
//utility header for byte writing and patterning

#include <stdlib.h>

//struct type to facilitate typed byte regions
struct ByteMark
{
        size_t block;
        unsigned char mark;
};

typedef struct ByteMark ByteMark;

//writes bytes from src to dest in size of block, with mark at the beginning of each block
void ByteWrite_mark(void* restrict dest,
                    void* restrict src,
                    size_t block,
                    unsigned char mark,
                    int amount);

// same as mark but keeps writing same src buffer over and over
void ByteWrite_rep(void* restrict dest,
                   void* restrict src,
                   size_t block,
                   unsigned char mark,
                   int amount);

//similar to mark but moves an unsigned char* as it writes
void ByteWrite_move(void* restrict dest,
                    unsigned char** restrict src,
                    size_t block,
                    unsigned char mark,
                    int amount);

#endif
