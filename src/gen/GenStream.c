#include "GenStream.h"

//double char ** used for movement across functions
int GenStream_gen(char** srcCode, ByteBuffer* bbuf)
{
        unsigned char* bop;
        ByteBuffer_READ_INC(bbuf, bop);
        GenStreamCheck checker;
        while(!GenStreamCheck_DONE(checker))
        {
                switch(**srcCode)
                {
                case ']':
                        return 1;
                case ' ':
                case '\n':
                case '\t':
                case '\v':
                        //white space
                        *srcCode += 1;
                        break;
                case '\0':
                        return 0; //error
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                        ByteBuffer_WRITE_DB(bbuf, strtod(*srcCode, srcCode));
                        checker.foundVal = 1;
                        break;
                case 'r':
                        if((*srcCode)[1] == 'n' && (*srcCode)[2] == 'g')
                        {
                                *bop = Instruction_Set_Zrange;
                                *srcCode += 3;
                                break;
                        }
                        else break;
                default:
                        return 0;
                }
        }
}
