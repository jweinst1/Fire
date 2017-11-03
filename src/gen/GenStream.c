#include "GenStream.h"

//double char ** used for movement across functions
void GenStream_gen(char** srcCode, ByteBuffer* bbuf)
{
        GenStreamCheck checker;
        while(!GenStreamCheck_DONE(checker))
        {
                switch(**srcCode)
                {
                case ']':
                        //stream expression end
                        break;
                case ' ':
                case '\n':
                case '\t':
                case '\v':
                        //white space
                        *srcCode += 1;
                        break;
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
                        //num start rng.
                        break;
                case 't':
                        //cmd expression
                        break;
                }
        }
}
