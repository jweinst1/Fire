#include "FireMachine.h"

void FireMachine_run(FireMachine* fmach, unsigned char* bytes)
{
        FireStream* fstPtr = &fmach->stream;

        while(*bytes)
        {
                switch(*bytes)
                {
                case 0: // stop code
                        return;
                case 1:
                        FireIO_PRINT(fstPtr);
                        bytes++;
                        break;
                case 2:
                        FireReduce_ADD(fstPtr);
                        bytes++;
                        break;
                case 3:
                        FireReduce_SUB(fstPtr);
                        bytes++;
                        break;
                case 4:
                        FireReduce_MUL(fstPtr);
                        bytes++;
                        break;
                case 5:
                        FireReduce_DIV(fstPtr);
                        bytes++;
                        break;
                case 6:
                        bytes++;
                        FireStream_PUSH_NUM(fstPtr, bytes);
                        bytes += sizeof(double);
                        break;
                case 7:
                        bytes++;
                        FireStream_PUSH_ZRNG(fstPtr, bytes);
                        bytes += sizeof(double);
                        break;
                //mapping macros
                case 8:
                        bytes++;
                        FireMap_ADD(fstPtr, *(double*)bytes);
                        bytes += sizeof(double);
                        break;
                case 9:
                        bytes++;
                        FireMap_SUB(fstPtr, *(double*)bytes);
                        bytes += sizeof(double);
                        break;
                case 10:
                        bytes++;
                        FireMap_MUL(fstPtr, *(double*)bytes);
                        bytes += sizeof(double);
                        break;
                case 11:
                        bytes++;
                        FireMap_DIV(fstPtr, *(double*)bytes);
                        bytes += sizeof(double);
                        break;
                case 12:
                        bytes++;
                        FireMap_REM(fstPtr, *(double*)bytes);
                        bytes += sizeof(double);
                        break;
                case 13:
                        FireMap_FLOOR(fstPtr);
                        bytes++;
                        break;
                case 14:
                        FireMap_SIN(fstPtr);
                        bytes++;
                        break;
                case 15:
                        FireMap_COS(fstPtr);
                        bytes++;
                        break;
                case 16:
                        FireMap_LOG(fstPtr);
                        bytes++;
                        break;
                case 17:
                        FireMap_EXP(fstPtr);
                        bytes++;
                        break;
                //filter macros
                case 18:
                        bytes++;
                        FireFilter_EQ(fstPtr, bytes);
                        break;
                case 19:
                        bytes++;
                        FireFilter_NOT_EQ(fstPtr, bytes);
                        break;
                case 20:
                        bytes++;
                        FireFilter_LT(fstPtr, bytes);
                        break;
                case 21:
                        bytes++;
                        FireFilter_GT(fstPtr, bytes);
                        break;
                case 22:
                        bytes++;
                        FireStream_SET_ZRNG(fstPtr, bytes);
                        bytes += sizeof(double);
                        break;
                default:
                        fmach->err = 1;
                        return;
                }
        }
}
