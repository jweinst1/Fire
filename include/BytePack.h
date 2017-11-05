#ifndef FIRE_BYTEPACK_H
#define FIRE_BYTEPACK_H
//contains packing and unpacking functions for objects to bytes

#include <stdlib.h>
#include <stdarg.h>

//takes the length of a format string, based on types specified
int BytePack_len(const char* fmt, size_t* length);

int BytePack_pack(void* buf, const char* fmt, ...);

//packs the same way but moves an unsigned char pointer to address
//after packing is finished
int BytePack_bpack(unsigned char** buf, const char* fmt, ...);

#endif
