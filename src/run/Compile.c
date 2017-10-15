#include "Compile.h"

void Compile_compile(char* code)
{
        Token tok;
        Executor exec;
        Exec_DEFAULT(exec);
        while(*code)
        {
                Tokenizer_Tokenize(code, &code, &tok);
                Exec_execute(&exec, &tok);
        }
}
