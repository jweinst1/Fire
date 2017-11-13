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
                        reader++;
                        printf("%lld ", *(int64_t*)reader);
                        reader += sizeof(int64_t);
                        break;
                default:
                        return 0;
                }
        }
        puts("]");
        return 1;
}

int FireIO_print_stream_nl(FireStream* stream)
{
        unsigned char* reader = stream->items;
        while(reader != stream->itemEnd)
        {
                switch(*reader)
                {
                case FireType_null:
                        reader++;
                        break;
                case FireType_Int:
                        reader++;
                        printf("%lld ", *(int64_t*)reader);
                        reader += sizeof(int64_t);
                        break;
                default:
                        return 0;
                }
        }
        printf("\n");
        return 1;
}
