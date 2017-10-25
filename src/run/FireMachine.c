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
                        bytes++;
                        FireStream_WRITE_NUM(fsPtr, bytes);
                        bytes += sizeof(double);
                        break;
                default:
                        fmach->err = 1;
                        return;
                }
        }
}
