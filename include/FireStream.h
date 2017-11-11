#ifndef FIRE_STREAM_H
#define FIRE_STREAM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>

#include "FireTypes.h"
#include "FireIO.h"

/*****Fire Stream Header******/
// Expandable buffer stream optimized for map, reduce and filter.
// FireStream can be shortened by simply moving end of buffer back and rewriting data, or expanded.
// FireStreams can be iterated over very quickly

//meant to fit 100 8-bit integers by default
#define FireStream_DEFAULT_SIZE 800

// macro calculates the length of stream
#define FireStream_LEN(stream) (stream->itemEnd - stream->items)

// macro calculates remaining space in stream
#define FireStream_SPACE(stream) (stream->end - stream->itemEnd)





//macro to check if realloc returns null, exits program if null pointer found
#define FireStream_reall_check(ptr, newSize) if((ptr = realloc(ptr, newSize)) == NULL) { \
                fprintf(stderr, "Memory error: Memory alloc for size %lu failed, out of memory.\n", newSize); \
                exit(1); \
                return 0; \
}


// struct to represent Fire's Stream

struct FireStream
{
        void* items;
        void* itemEnd;
        void* end;
        size_t cap;
};

typedef struct FireStream FireStream;


// returns the length in bytes of the elements in the stream.
static inline size_t
FireStream_len(FireStream* stream)
{
        return stream->itemEnd - stream->items;
}

// returns the space remaining in the stream.
static inline size_t
FireStream_space(FireStream* stream)
{
        return stream->end - stream->itemEnd;
}

// Checks if the stream can fit some size of data.
static inline int
FireStream_fits(FireStream* stream, size_t size)
{
        return FireStream_space(stream) > size;
}

// Resets the write head of the stream to the beginning, allowing reusage of existing memory.
// This saves reallocation of memory during mapping, filtering, etc.
static inline void
FireStream_reset(FireStream* stream)
{
        stream->itemEnd = stream->items;
}

static inline void
FireStream_nullify(FireStream* stream)
{
        for(unsigned char* ptr = stream->items; ptr != stream->end; ptr++) *ptr = 0;
}

// expands the stream to a newsize, returns 0 if realloc failure
int FireStream_expand(FireStream* stream, size_t newSize);

//expands to twice the current size.
int FireStream_expand_2x(FireStream* stream);

static inline void
FireStream_expand_if(FireStream* stream, size_t size)
{
        if(FireStream_space(stream) < size) FireStream_expand(stream, size);
}

static inline void
FireStream_shorten(FireStream* stream, size_t size) {
        if(size < FireStream_len(stream)) stream->itemEnd = stream->items + size;
}

// creates a stream from a pointer using default size.
void FireStream_make(FireStream* stream);

//creates a stream with custom size.
void FireStream_make_size(FireStream* stream, size_t size);

//frees a stream and sets the buffer to zero and NULL
void FireStream_free(FireStream* stream);

//**** Write Methods *****

//function to write any type, given some known size and address
static inline void
FireStream_write_any(FireStream* stream, void* val, size_t size)
{
        FireStream_expand_if(stream, size);
        memcpy(stream->itemEnd, val, size);
        stream->itemEnd += size;
}

static inline void
FireStream_write_i8(FireStream* stream, int8_t num)
{
        FireStream_expand_if(stream, sizeof(int8_t));
        *(int8_t*)(stream->itemEnd) = num;
        stream->itemEnd += sizeof(int8_t);
}

static inline void
FireStream_write_u8(FireStream* stream, uint8_t num)
{
        FireStream_expand_if(stream, sizeof(uint8_t));
        *(uint8_t*)(stream->itemEnd) = num;
        stream->itemEnd += sizeof(uint8_t);
}

static inline void
FireStream_write_i16(FireStream* stream, int16_t num)
{
        FireStream_expand_if(stream, sizeof(int16_t));
        *(int16_t*)(stream->itemEnd) = num;
        stream->itemEnd += sizeof(int16_t);
}

static inline void
FireStream_write_u16(FireStream* stream, uint16_t num)
{
        FireStream_expand_if(stream, sizeof(uint16_t));
        *(uint16_t*)(stream->itemEnd) = num;
        stream->itemEnd += sizeof(uint16_t);
}

static inline void
FireStream_write_i32(FireStream* stream, int32_t num)
{
        FireStream_expand_if(stream, sizeof(int32_t));
        *(int32_t*)(stream->itemEnd) = num;
        stream->itemEnd += sizeof(int32_t);
}

static inline void
FireStream_write_u32(FireStream* stream, uint32_t num)
{
        FireStream_expand_if(stream, sizeof(uint32_t));
        *(uint32_t*)(stream->itemEnd) = num;
        stream->itemEnd += sizeof(uint32_t);
}

static inline void
FireStream_write_i64(FireStream* stream, int64_t num)
{
        FireStream_expand_if(stream, sizeof(int64_t));
        *(int64_t*)(stream->itemEnd) = num;
        stream->itemEnd += sizeof(int64_t);
}

static inline void
FireStream_write_u64(FireStream* stream, uint64_t num)
{
        FireStream_expand_if(stream, sizeof(uint64_t));
        *(uint64_t*)(stream->itemEnd) = num;
        stream->itemEnd += sizeof(uint64_t);
}

static inline void
FireStream_write_dbl(FireStream* stream, double num)
{
        FireStream_expand_if(stream, sizeof(double));
        *(double*)(stream->itemEnd) = num;
        stream->itemEnd += sizeof(double);
}

// copies contents of stream to a void*
static inline void
FireStream_copy(FireStream* stream, void* dst)
{
        memcpy(dst, stream->items, FireStream_len(stream));
}

//writes or "packs" a series of variadic arguments into the binary stream
int FireStream_write_fmt(FireStream* stream, const char* fmt, ...);

// gets the ptr at some offset, bound checked.
static inline void*
FireStream_get_at_off(FireStream* stream, size_t offset)
{
        if(offset < FireStream_len(stream)) return stream->items + offset;
        else return NULL;
}

static inline void
FireStream_set_buf(FireStream* stream, void** buf)
{
        *buf = stream->items;
}

//reads one u8 from the stream
static inline void
FireStream_read_u8(FireStream* stream, uint8_t* ptr)
{
        *ptr = *(uint8_t*)(stream->items);
}

//reads one u8 from the stream at some offset
static inline void
FireStream_read_u8_at(FireStream* stream, uint8_t* ptr, size_t offset)
{
        *ptr = *(uint8_t*)(stream->items + offset);
}

//reads one i8 from the stream
static inline void
FireStream_read_i8(FireStream* stream, int8_t* ptr)
{
        *ptr = *(int8_t*)(stream->items);
}

//reads one i8 from the stream
static inline void
FireStream_read_i8_at(FireStream* stream, int8_t* ptr, size_t offset)
{
        *ptr = *(int8_t*)(stream->items + offset);
}

//reads one dbl from the stream
static inline void
FireStream_read_dbl(FireStream* stream, double* ptr)
{
        *ptr = *(double*)(stream->items);
}

//reads one dbl from the stream at an offset
static inline void
FireStream_read_dbl_at(FireStream* stream, double* ptr, size_t offset)
{
        *ptr = *(double*)(stream->items + offset);
}

//read a specified amount of bytes into a buffer
static inline void
FireStream_read_n(FireStream* stream, void* buf, size_t size)
{
        memcpy(buf, stream->items, size);
}

//read n bytes from stream into buf at some offset.
static inline void
FireStream_read_n_at(FireStream* stream, void* buf, size_t size, size_t offset)
{
        memcpy(buf, stream->items + offset, size);
}

static inline int
FireStream_is_empty(FireStream* stream)
{
        return stream->items == stream->itemEnd;
}

//returns percentage of capacity used, for optimization
static inline double
FireStream_cap_used(FireStream* stream)
{
        return (double)(stream->itemEnd - stream->items)/(double)(stream->cap);
}

//reads a certain number of elements from format to buf.
int FireStream_read_fmt(FireStream* stream, void* buf, const char* fmt);




#endif
