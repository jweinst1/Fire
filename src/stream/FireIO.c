#include "FireIO.h"

int FireIO_print_stream(FireStream* stream)
{
        unsigned char* reader = stream->items;
        printf("[ ");
        while(reader != stream->itemEnd)
        {
                switch(*reader)
                {
                case FireType_null:
                        reader++;
                        break;
                case FireType_Int:
                        printf("%ld ", *(int64_t*)reader);
                        reader += sizeof(int64_t);
                        break;
                default:
                        return 0;
                }
        }
        puts("]");
        return 1;
}
