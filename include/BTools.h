#ifndef FIRE_BTOOLS_H
#define FIRE_BTOOLS_H
// this header provides some useful macros for working with bytes and void*

//puts an 8bit signed integer in void*
#define BTools_PUT_CH(bytes, num) *(char*)bytes = num

#define BTools_PUT_UCH(bytes, num) *(unsigned char*)bytes = num

#define BTools_PUT_SHORT(bytes, num) *(short*)bytes = num

#define BTools_PUT_USHORT(bytes, num) *(unsigned short*)bytes = num

#define BTools_PUT_INT(bytes, num) *(int*)bytes = num

#define BTools_PUT_UINT(bytes, num) *(unsigned int*)bytes = num

#define BTools_PUT_LONG(bytes, num) *(long*)bytes = num

#define BTools_PUT_ULONG(bytes, num) *(unsigned long*)bytes = num

#define BTools_PUT_DB(bytes, num) *(double*)bytes = num

//puts byte unsigned and increments
#define BTools_PUTI_UCH(bytes, num) *(unsigned char*)(bytes++) = num

#define BTools_PUTI_CH(bytes, num) *(char*)(bytes++) = num

//puts double and moves by sizeof double in one expression
#define BTools_PUTI_DB(bytes, num) bytes += sizeof(double) + ((*(double*)bytes = num) * 0)

#define BTools_PUTI_INT(bytes, num) bytes += sizeof(int) + ((*(int*)bytes = num) * 0)

#define BTools_PUTI_LONG(bytes, num) bytes += sizeof(long) + ((*(long*)bytes = num) * 0)

//PAIR TOOLS
//write binary pairs, a byte and long, etc.

#define BTools_UCH_DB(bytes, uch, db) do { \
                *(unsigned char*)(bytes++) = uch; \
                *(double*)bytes = db; \
} while(0)

#define BTools_UCH_LG(bytes, uch, lg) do { \
                *(unsigned char*)(bytes++) = uch; \
                *(long*)bytes = lg; \
} while(0)

//write and move pair tools

#define BTools_UCH_DB_M(bytes, uch, db) do { \
                *(unsigned char*)(bytes++) = uch; \
                *(double*)bytes = db; \
                bytes += sizeof(double); \
} while(0)

#define BTools_UCH_LG_M(bytes, uch, lg) do { \
                *(unsigned char*)(bytes++) = uch; \
                *(long*)bytes = lg; \
                bytes += sizeof(long); \
} while(0)

//memory writing tools, for sequences of untyped bytes

#define BTools_WRITE(dest, src, n) while (n--) { \
                *dest++ = *src++; \
}

#endif
