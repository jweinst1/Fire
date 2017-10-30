#ifndef FIRE_BTOOLS_H
#define FIRE_BTOOLS_H
// this header provides some useful macros for working with bytes and void*

//puts an 8bit signed integer in void*
#define BTools_PUT_I8(bytes, num) *(char*)bytes = num

#define BTools_PUT_U8(bytes, num) *(unsigned char*)bytes = num

#endif
