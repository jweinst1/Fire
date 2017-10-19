#ifndef FIRE_STRING_H
#define FIRE_STRING_H

//fire string object

#include <stdlib.h>
#include <string.h>

struct FireString
{
        char* chrs;
        size_t len;
        size_t cap;
};

typedef struct FireString FireString;

static inline FireString*
FireString_new(size_t capacity)
{
        FireString* fStr = malloc(sizeof(FireString));
        fStr->chrs = malloc(sizeof(char) * capacity * 2);
        fStr->cap = capacity * 2;
        fStr->len = 0;
        return fStr;
}

static inline void
FireString_expand(FireString* fStr, size_t amount)
{
        fStr->chrs = realloc(fStr->chrs, fStr->cap + amount);
        if(fStr->chrs) fStr->cap += amount;
        else return; //needs error handling
}

static inline void
FireString_concat(FireString* fs1, FireString* fs2) {
        if(fs1->cap > fs1->len + fs2->len) strcat(fs1->chrs, fs2->chrs);
        else {
                FireString_expand(fs1, (fs1->len + fs2->len) * 4);
                strcat(fs1->chrs, fs2->chrs);
        }
}

static inline void
FireString_free(FireString* fStr)
{
        free(fStr->chrs);
        fStr->chrs = NULL;
        free(fStr);
}

#endif
