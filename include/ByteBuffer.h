#ifndef FIRE_BYTE_BUFFER_H
#define FIRE_BYTE_BUFFER_H
// contains byte buffer object for fast writing of bytecode

#include <stdlib.h>
#include <string.h>

#define ByteBuffer_DEFAULT_SIZE 2000

struct ByteBuffer
{
        unsigned char* bytes;
        unsigned char* mark;
        unsigned char* end;
};

typedef struct ByteBuffer ByteBuffer;

//ptr init
#define ByteBuffer_INIT(bbuf) do { \
                bbuf->bytes = malloc(ByteBuffer_DEFAULT_SIZE); \
                bbuf->mark = bbuf->bytes; \
                bbuf->end = bbuf->bytes + ByteBuffer_DEFAULT_SIZE; \
} while(0)

//literla init
#define ByteBuffer_INITL(bbuf) do { \
                bbuf.bytes = malloc(ByteBuffer_DEFAULT_SIZE); \
                bbuf.mark = bbuf.bytes; \
                bbuf.end = bbuf.bytes + ByteBuffer_DEFAULT_SIZE; \
} while(0)


#define ByteBuffer_LEN(bbuf) (bbuf->mark - bbuf->bytes)

#define ByteBuffer_SPACE(bbuf) (bbuf->end - bbuf->mark)

#define ByteBuffer_CAP(bbuf) (bbuf->end - bbuf->bytes)

//conditionally expands at less than 20 bytes remaining
#define ByteBuffer_EXPAND_IF(bbuf) do { \
                if(ByteBuffer_SPACE(bbuf) < 20 ) { \
                        size_t markLen = bbuf->mark - bbuf->bytes; \
                        size_t newCap = ByteBuffer_CAP(bbuf) * 2; \
                        bbuf->bytes = realloc(bbuf->bytes, newCap); \
                        bbuf->mark = bbuf->bytes + markLen; \
                        bbuf->end = bbuf->bytes + newCap; \
                } \
} while(0)
// writes one unsigned char
#define ByteBuffer_WRITE(bbuf, byte) do { \
                ByteBuffer_EXPAND_IF(bbuf); \
                *(bbuf->mark++) = byte; \
} while(0)

//writes one double.
#define ByteBuffer_WRITE_DB(bbuf, num) do { \
                ByteBuffer_EXPAND_IF(bbuf); \
                *(double*)(bbuf->mark) = num; \
                bbuf->mark += sizeof(double); \
} while(0)

//writes an unsigned char then a double.
#define ByteBuffer_WRITE_BDB(bbuf, byte, num) do { \
                ByteBuffer_EXPAND_IF(bbuf); \
                *(bbuf->mark++) = byte; \
                *(double*)(bbuf->mark) = num; \
                bbuf->mark += sizeof(double); \
} while(0)

//reads one byte and increments
#define ByteBuffer_READ_INC(bbuf, byte) byte = bbuf->mark++

#endif
