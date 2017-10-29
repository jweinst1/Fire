#ifndef FIRE_FILTER_H
#define FIRE_FILTER_H
//file that contains filtering macros

#include <string.h>
#include "FireTypes.h"

// compares and filters stream against value for equality
#define FireFilter_EQ(stream, value) do { \
                unsigned char* reader = stream->items; \
                void* writer = stream->items; \
                while(reader != stream->itemEnd) { \
                        if(*reader == FireStream_TYPE_NUM) { \
                                if(!memcmp(++reader, value, sizeof(double))) { \
                                        *(unsigned char*)writer = FireStream_TYPE_NUM; \
                                        memcpy(++writer, reader, sizeof(double)); \
                                        writer += sizeof(double); reader += sizeof(double); \
                                } \
                                else { \
                                        reader += sizeof(double); \
                                } \
                        } \
                } \
                stream->itemEnd = writer; \
} while(0)

// Compares and filters a value against the stream for inequality
#define FireFilter_NOT_EQ(stream, value) do { \
                unsigned char* reader = stream->items; \
                void* writer = stream->items; \
                while(reader != stream->itemEnd) { \
                        if(*reader == FireStream_TYPE_NUM) { \
                                if(memcmp(++reader, value, sizeof(double)) != 0) { \
                                        *(unsigned char*)writer = FireStream_TYPE_NUM; \
                                        memcpy(++writer, reader, sizeof(double)); \
                                        writer += sizeof(double); reader += sizeof(double); \
                                } \
                                else { \
                                        reader += sizeof(double); \
                                } \
                        } \
                } \
                stream->itemEnd = writer; \
} while(0)

#define FireFilter_GT(stream, value) do { \
                unsigned char* reader = stream->items; \
                void* writer = stream->items; \
                while(reader != stream->itemEnd) { \
                        if(*reader == FireStream_TYPE_NUM) { \
                                reader++; \
                                if(*(double*)reader > *(double*)value) { \
                                        *(unsigned char*)writer = FireStream_TYPE_NUM; \
                                        memcpy(++writer, reader, sizeof(double)); \
                                        writer += sizeof(double); reader += sizeof(double); \
                                } \
                                else { \
                                        reader += sizeof(double); \
                                } \
                        } \
                } \
                stream->itemEnd = writer; \
} while(0)

#define FireFilter_LT(stream, value) do { \
                unsigned char* reader = stream->items; \
                void* writer = stream->items; \
                while(reader != stream->itemEnd) { \
                        if(*reader == FireStream_TYPE_NUM) { \
                                reader++; \
                                if(*(double*)reader < *(double*)value) { \
                                        *(unsigned char*)writer = FireStream_TYPE_NUM; \
                                        memcpy(++writer, reader, sizeof(double)); \
                                        writer += sizeof(double); reader += sizeof(double); \
                                } \
                                else { \
                                        reader += sizeof(double); \
                                } \
                        } \
                } \
                stream->itemEnd = writer; \
} while(0)

#endif
