#include "CodeGen.h"
#include "GenStream.h"


int CodeGen_Generate(char* srcCode, ByteBuffer* buffer)
{
        while(*srcCode)
        {
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

                        break;
                case '<':
                        if(srcCode[1] == '<')
                        {

                        }
                        break;
                case '[':
                        //stream literal, concept needs refining
                        srcCode++;
                        //GenStream_gen(&srcCode, buffer);
                        break;
                default:
                        return 0;
                        break;
                }
        }
        return 1;
}
