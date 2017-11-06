#include <stdlib.h>
#include "GenFilter.h"

int GenFilter_gen(char** srcCode, ByteBuffer* buf)
{
        while(**srcCode)
        {
                switch(**srcCode)
                {
                case ' ':
                case '\n':
                case '\t':
                case '\v':
                        //ws
                        *srcCode += 1;
                        break;
                case '=':
                        if((*srcCode)[1] == '=')
                        {
                                *srcCode += 2;
                                ByteBuffer_WRITE(buf, Instruction_Filt_Eq);
                                while(isspace(**srcCode)) *srcCode += 1;
                                if(isdigit(**srcCode) || **srcCode == '-')
                                {
                                        ByteBuffer_WRITE_DB(buf, strtod(*srcCode, srcCode));
                                        return 1;
                                }
                                else return 0;
                        }
                        else return 0;
                        break;
                case '!':
                        if((*srcCode)[1] == '=')
                        {
                                *srcCode += 2;
                                ByteBuffer_WRITE(buf, Instruction_Filt_Neq);
                                while(isspace(**srcCode)) *srcCode += 1;
                                if(isdigit(**srcCode) || **srcCode == '-')
                                {
                                        ByteBuffer_WRITE_DB(buf, strtod(*srcCode, srcCode));
                                        return 1;
                                }
                                else return 0;
                        }
                        else return 0;
                        break;
                case '>':
                        *srcCode += 1;
                        ByteBuffer_WRITE(buf, Instruction_Filt_Gt);
                        while(isspace(**srcCode)) *srcCode += 1;
                        if(isdigit(**srcCode) || **srcCode == '-')
                        {
                                ByteBuffer_WRITE_DB(buf, strtod(*srcCode, srcCode));
                                return 1;
                        }
                        else return 0;
                        break;
                case '<':
                        *srcCode += 1;
                        ByteBuffer_WRITE(buf, Instruction_Filt_Lt);
                        while(isspace(**srcCode)) *srcCode += 1;
                        if(isdigit(**srcCode) || **srcCode == '-')
                        {
                                ByteBuffer_WRITE_DB(buf, strtod(*srcCode, srcCode));
                                return 1;
                        }
                        else return 0;
                        break;
                default:
                        return 0;
                }
        }
        //case null ch found before gen complete
        return 0;
}
