#include "FireMachine.h"

void FireMachine_run(FireMachine* fmach, unsigned char* bytes)
{
        FireStream* fstPtr = &fmach->stream;

        while(*bytes)
        {
                switch(*bytes)
                {
                case Instruction_Null: // stop code
                        return;
                case Instruction_Print:
                        FireIO_PRINT(fstPtr);
                        bytes++;
                        break;
                case Instruction_Reduce_Add:
                        FireReduce_ADD(fstPtr);
                        bytes++;
                        break;
                case Instruction_Reduce_Sub:
                        FireReduce_SUB(fstPtr);
                        bytes++;
                        break;
                case Instruction_Reduce_Mul:
                        FireReduce_MUL(fstPtr);
                        bytes++;
                        break;
                case Instruction_Reduce_Div:
                        FireReduce_DIV(fstPtr);
                        bytes++;
                        break;
                case Instruction_Push_Number:
                        bytes++;
                        FireStream_PUSH_NUM(fstPtr, bytes);
                        bytes += sizeof(double);
                        break;
                case Instruction_Push_ZRange:
                        bytes++;
                        FireStream_PUSH_ZRNG(fstPtr, bytes);
                        bytes += sizeof(double);
                        break;
                //mapping macros
                case Instruction_Map_Add:
                        bytes++;
                        FireMap_ADD(fstPtr, *(double*)bytes);
                        bytes += sizeof(double);
                        break;
                case Instruction_Map_Sub:
                        bytes++;
                        FireMap_SUB(fstPtr, *(double*)bytes);
                        bytes += sizeof(double);
                        break;
                case Instruction_Map_Mul:
                        bytes++;
                        FireMap_MUL(fstPtr, *(double*)bytes);
                        bytes += sizeof(double);
                        break;
                case Instruction_Map_Div:
                        bytes++;
                        FireMap_DIV(fstPtr, *(double*)bytes);
                        bytes += sizeof(double);
                        break;
                case Instruction_Map_Rem:
                        bytes++;
                        FireMap_REM(fstPtr, *(double*)bytes);
                        bytes += sizeof(double);
                        break;
                case Instruction_Map_Floor:
                        FireMap_FLOOR(fstPtr);
                        bytes++;
                        break;
                case Instruction_Map_Sin:
                        FireMap_SIN(fstPtr);
                        bytes++;
                        break;
                case Instruction_Map_Cos:
                        FireMap_COS(fstPtr);
                        bytes++;
                        break;
                case Instruction_Map_Log:
                        FireMap_LOG(fstPtr);
                        bytes++;
                        break;
                case Instruction_Map_Exp:
                        FireMap_EXP(fstPtr);
                        bytes++;
                        break;
                //filter macros
                case Instruction_Filt_Eq:
                        bytes++;
                        FireFilter_EQ(fstPtr, bytes);
                        break;
                case Instruction_Filt_Neq:
                        bytes++;
                        FireFilter_NOT_EQ(fstPtr, bytes);
                        break;
                case Instruction_Filt_Lt:
                        bytes++;
                        FireFilter_LT(fstPtr, bytes);
                        break;
                case Instruction_Filt_Gt:
                        bytes++;
                        FireFilter_GT(fstPtr, bytes);
                        break;
                case Instruction_Set_Zrange:
                        bytes++;
                        FireStream_SET_ZRNG(fstPtr, *(double*)bytes);
                        bytes += sizeof(double);
                        break;
                default:
                        fmach->err = 1;
                        return;
                }
        }
}
