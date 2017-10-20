#ifndef FIRE_BUFFER_H
#define FIRE_BUFFER_H
//this header contains macros to manipulate buffers on the token (void*)

#include <stdlib.h>
#include <string.h>

#define Token_DEFAULT_SIZE 200

#define Buffer_SET_1ST(token, type, val) ((type*)token->buf)[0] = val

#define Buffer_EXPAND(token) token->buf = realloc(token->buf, (token->capacity*= 2))

#endif
