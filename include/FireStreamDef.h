#ifndef FIRE_STREAM_DEF_H
#define FIRE_STREAM_DEF_H

//macro that allows other files to implement stream methods
#define FireStream_DECLARE struct FireStream;

//meant to fit 100 8-bit integers by default
#define FireStream_DEFAULT_SIZE 800

// struct to represent Fire's Stream

struct FireStream
{
        void* items;
        void* itemEnd;
        void* end;
        size_t cap;
};

typedef struct FireStream FireStream;

#endif
