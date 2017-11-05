#include "BytePack.h"


int BytePack_len(const char* fmt, size_t* length)
{
        while(*fmt)
        {
                switch(*fmt)
                {
                case 'i':
                        *length += sizeof(int);
                        break;
                case 's':
                        *length += sizeof(short);
                        break;
                case 'l':
                        *length += sizeof(long);
                        break;
                case 'd':
                        *length += sizeof(double);
                        break;
                case 'b':
                        *length += sizeof(unsigned char);
                        break;
                case 'c':
                        *length += sizeof(char);
                        break;
                case 'z':
                        *length += sizeof(size_t);
                        break;
                default:
                        return 0; //error
                }
                fmt++;
        }
        return 1;
}

int BytePack_pack(void* buf, const char* fmt, ...)
{
        void* writer = buf;
        va_list pargs;
        va_start(pargs, fmt);
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
                        *(short*)writer = va_arg(pargs, int);
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
                        *(unsigned char*)writer = va_arg(pargs, int);
                        writer += sizeof(unsigned char);
                        fmt++;
                        break;
                case 'c':
                        *(char*)writer = va_arg(pargs, int);
                        writer += sizeof(char);
                        fmt++;
                        break;
                case 'z':
                        *(size_t*)writer = va_arg(pargs, size_t);
                        writer += sizeof(size_t);
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

int BytePack_bpack(unsigned char** buf, const char* fmt, ...)
{
        void* writer = *buf;
        va_list pargs;
        va_start(pargs, fmt);
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
                        *(short*)writer = va_arg(pargs, int);
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
                        *(unsigned char*)writer = va_arg(pargs, int);
                        writer += sizeof(unsigned char);
                        fmt++;
                        break;
                case 'c':
                        *(char*)writer = va_arg(pargs, int);
                        writer += sizeof(char);
                        fmt++;
                        break;
                case 'z':
                        *(size_t*)writer = va_arg(pargs, size_t);
                        writer += sizeof(size_t);
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
