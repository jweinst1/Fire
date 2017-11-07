#include "FireStream.h"

void FireStream_Make(FireStream* stream)
{
        stream->items = malloc(FireStream_DEFAULT_SIZE);
        stream->cap = FireStream_DEFAULT_SIZE;
        stream->end = stream->items + stream->cap;
        stream->itemEnd = stream->items;
}
