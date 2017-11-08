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
