#include "FireMachine.h"

void FireMachine_run(FireMachine* fmach, unsigned char* bytes)
{
        FireStream* fsPtr = &fmach->stream;
        while(*bytes)
        {
                switch(*bytes)
                {
                case 0: // stop code
                        return;
                case 1:
                        FireIO_PRINT(fsPtr);
                        bytes++;
                        break;
                case 2:
                        FireReduce_ADD(fsPtr);
                        bytes++;
                        break;
                case 3:
                        FireReduce_SUB(fsPtr);
                        bytes++;
                        break;
                case 4:
                        FireReduce_MUL(fsPtr);
                        bytes++;
                        break;
                case 5:
                        FireReduce_DIV(fsPtr);
                        bytes++;
                        break;
                case 6:
                        bytes++;
                        FireStream_PUSH_NUM(fsPtr, bytes);
                        bytes += sizeof(double);
                        break;
                case 7:
                        bytes++;
                        FireStream_PUSH_ZRNG(fsPtr, bytes);
                        bytes += sizeof(double);
                        break;
                case 8:
                        bytes++;
                        FireMap_ADD(fsPtr, *(double*)bytes);
                        bytes += sizeof(double);
                        break;
                case 9:
                        bytes++;
                        FireMap_SUB(fsPtr, *(double*)bytes);
                        bytes += sizeof(double);
                        break;
                case 10:
                        bytes++;
                        FireMap_MUL(fsPtr, *(double*)bytes);
                        bytes += sizeof(double);
                        break;
                case 11:
                        bytes++;
                        FireMap_DIV(fsPtr, *(double*)bytes);
                        bytes += sizeof(double);
                        break;
                case 12:
                        bytes++;
                        FireMap_REM(fsPtr, *(double*)bytes);
                        bytes += sizeof(double);
                        break;
                case 13:
                        FireMap_FLOOR(fsPtr);
                        bytes++;
                        break;
                default:
                        fmach->err = 1;
                        return;
                }
        }
}
