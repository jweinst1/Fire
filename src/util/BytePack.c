#include "BytePack.h"

int BytePack_pack(void* buf, const char* fmt, ...)
{
        void* writer = buf;
        size_t argLen = strlen(fmt);
        va_list pargs;
        va_start(pargs, argLen);
        while(*fmt)
        {
                switch(*fmt)
                {
                case 'i':
                        *(int*)writer = va_arg(pargs, int);
                        writer += sizeof(int);
                        fmt++;
                        break;
                case 's':
                        *(short*)writer = va_arg(pargs, short);
                        writer += sizeof(short);
                        fmt++;
                        break;
                case 'l':
                        *(long*)writer = va_arg(pargs, long);
                        writer += sizeof(long);
                        fmt++;
                        break;
                case 'd':
                        *(double*)writer = va_arg(pargs, double);
                        writer += sizeof(double);
                        fmt++;
                        break;
                case 'b':
                        *(unsigned char*)writer = va_arg(pargs, unsigned char);
                        writer += sizeof(unsigned char);
                        fmt++;
                        break;
                case 'c':
                        *(char*)writer = va_arg(pargs, char);
                        writer += sizeof(char);
                        fmt++;
                        break;
                default:
                        //non-recognized format
                        va_end(pargs);
                        return 0;
                }
        }
        va_end(pargs);
        return 1;
}
