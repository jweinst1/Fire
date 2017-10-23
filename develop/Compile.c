#include "Compile.h"
#include <stdio.h>

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

//alternative compile that runs with debug formatting.
void Compile_debug(char* code)
{
        Token tok;
        Executor exec;
        Exec_DEFAULT(exec);
        while(*code)
        {
                puts("iter");
                printf("Code:[%s]\n", code);
                Tokenizer_Tokenize(code, &code, &tok);
                printf("Token type : %d\n", tok.type);
                Exec_execute(&exec, &tok);
                printf("exec tok state: %d\n", exec.state);
        }
}
