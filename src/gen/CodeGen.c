#include "CodeGen.h"
#include "GenReduce.h"


int CodeGen_Generate(char* srcCode, ByteBuffer* buffer, GenState* state)
{
        while(*srcCode)
        {
                switch(*state)
                {
                case GenState_AccProc:
                        switch(*srcCode)
                        {
                        case ' ':
                        case '\n':
                        case '\t':
                        case '\v':
                                srcCode++; //white space
                                break;
                        case '{':
                                srcCode++; //reducer sym
                                if(!GenReduce_gen(&srcCode, buffer)) return 0;
                                *state = GenState_AccNext;
                                break;
                        case 'p':
                                if(srcCode[1] == 'u' && srcCode[2] == 's' && srcCode[3] == 'h')
                                {
                                        srcCode += 4;
                                        CodeGen_ADV_WS(srcCode);
                                        if(isdigit(*srcCode) || *srcCode == '-')
                                        {
                                                ByteBuffer_WRITE_BDB(buffer, Instruction_Push_Number, strtod(srcCode, &srcCode));
                                                *state = GenState_AccNext;
                                                break;
                                        }
                                        else return 0; //error
                                }
                                else return 0; // error
                                break;
                        case 'o':
                                if(srcCode[1] == 'u' && srcCode[2] == 't')
                                {
                                        srcCode += 3;
                                        ByteBuffer_WRITE(buffer, Instruction_Print);
                                        *state = GenState_AccNext;
                                        break;
                                }
                                else return 0;
                                break;
                        case 'r':
                                if(srcCode[1] == 'n' && srcCode[2] == 'g')
                                {
                                        srcCode += 3;
                                        CodeGen_ADV_WS(srcCode);
                                        if(isdigit(*srcCode) || *srcCode == '-')
                                        {
                                                ByteBuffer_WRITE_BDB(buffer, Instruction_Push_ZRange, strtod(srcCode, &srcCode));
                                                *state = GenState_AccNext;
                                                break;
                                        }
                                        else return 0; //error
                                }
                                break;
                        case '+':
                                srcCode++;
                                CodeGen_ADV_WS(srcCode);
                                if(isdigit(*srcCode) || *srcCode == '-')
                                {
                                        ByteBuffer_WRITE_BDB(buffer, Instruction_Map_Add, strtod(srcCode, &srcCode));
                                        *state = GenState_AccNext;
                                        break;
                                }
                                else return 0; //error
                        case '-':
                                srcCode++;
                                CodeGen_ADV_WS(srcCode);
                                if(isdigit(*srcCode) || *srcCode == '-')
                                {
                                        ByteBuffer_WRITE_BDB(buffer, Instruction_Map_Sub, strtod(srcCode, &srcCode));
                                        *state = GenState_AccNext;
                                        break;
                                }
                                else return 0;  //error
                        case '*':
                                srcCode++;
                                CodeGen_ADV_WS(srcCode);
                                if(isdigit(*srcCode) || *srcCode == '-')
                                {
                                        ByteBuffer_WRITE_BDB(buffer, Instruction_Map_Mul, strtod(srcCode, &srcCode));
                                        *state = GenState_AccNext;
                                        break;
                                }
                                else return 0;         //error
                        case '/':
                                srcCode++;
                                CodeGen_ADV_WS(srcCode);
                                if(isdigit(*srcCode) || *srcCode == '-')
                                {
                                        ByteBuffer_WRITE_BDB(buffer, Instruction_Map_Div, strtod(srcCode, &srcCode));
                                        *state = GenState_AccNext;
                                        break;
                                }
                                else return 0;         //error
                        case '%':
                                srcCode++;
                                CodeGen_ADV_WS(srcCode);
                                if(isdigit(*srcCode) || *srcCode == '-')
                                {
                                        ByteBuffer_WRITE_BDB(buffer, Instruction_Map_Rem, strtod(srcCode, &srcCode));
                                        *state = GenState_AccNext;
                                        break;
                                }
                                else return 0;         //error
                        default:
                                return 0;
                                break;
                        }
                        break;
                case GenState_AccNext:
                        CodeGen_ADV_WS(srcCode);
                        if(srcCode[0] == '-' && srcCode[1] == '>')
                        {
                                srcCode += 2;
                                *state = GenState_AccProc;
                                break;
                        }
                        else return 0;
                        break;
                }

        }
        return 1;
}
