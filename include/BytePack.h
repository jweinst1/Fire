#ifndef FIRE_BYTEPACK_H
#define FIRE_BYTEPACK_H
//contains packing and unpacking functions for objects to bytes

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

int BytePack_pack(void* buf, const char* fmt, ...);

#endif
