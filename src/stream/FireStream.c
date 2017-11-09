#include "FireStream.h"


int FireStream_expand(FireStream* stream, size_t newSize)
{
        size_t ilen = FireStream_len(stream);
        FireStream_reall_check(stream->items, newSize);
        stream->cap = newSize;
        stream->end = stream->items + newSize;
        stream->itemEnd = stream->items + ilen;
        return 1;
}

int FireStream_expand_2x(FireStream* stream)
{
        size_t ilen = FireStream_len(stream);
        FireStream_reall_check(stream->items, (stream->cap * 2));
        stream->cap *= 2;
        stream->end = stream->items + stream->cap;
        stream->itemEnd = stream->items + ilen;
        return 1;
}

void FireStream_make(FireStream* stream)
{
        stream->items = malloc(FireStream_DEFAULT_SIZE);
        stream->cap = FireStream_DEFAULT_SIZE;
        stream->end = stream->items + stream->cap;
        stream->itemEnd = stream->items;
}

void FireStream_make_size(FireStream* stream, size_t size)
{
        stream->items = malloc(size);
        stream->cap = size;
        stream->end = stream->items + stream->cap;
        stream->itemEnd = stream->items;
}

void FireStream_free(FireStream* stream)
{
        free(stream->items);
        stream->items = NULL;
        stream->itemEnd = NULL;
        stream->end = NULL;
        stream->cap = 0;
}

int FireStream_write_fmt(FireStream* stream, const char* fmt, ...)
{
        va_list pargs;
        va_start(pargs, fmt);
        while(*fmt)
        {
                switch(*fmt)
                {
                case 'b':
                        FireStream_write_u8(stream, va_arg(pargs, int));
                        break;
                case 'i':
                        FireStream_write_i32(stream, va_arg(pargs, int32_t));
                        break;
                case 'l':
                        FireStream_write_i64(stream, va_arg(pargs, int64_t));
                        break;
                case 'd':
                        FireStream_write_dbl(stream, va_arg(pargs, double));
                        break;
                case 'c':
                        FireStream_write_i8(stream, va_arg(pargs, int));
                        break;
                default:
                        va_end(pargs);
                        return 0; //error
                }
                fmt++;
        }
        va_end(pargs);
        return 1;
}

int FireStream_read_fmt(FireStream* stream, void* buf, const char* fmt)
{
        void* reader = stream->items;
        while(*fmt)
        {
                switch(*fmt)
                {
                case 'b':
                        *(uint8_t*)buf = *(uint8_t*)reader;
                        reader += sizeof(uint8_t);
                        break;
                case 'i':
                case 'l':
                case 'd':
                case 'c':
                default:
                        return 0; //error in fmt
                }
                fmt++;
        }
        return 1;
}
