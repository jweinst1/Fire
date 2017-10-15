#include <stdio.h>
#include "Tokenizer.h"
#include "Exec.h"

int main( int argc, char *argv[] )
{
        char* code = "6 -> + 4 -> out";
        Token tok;
        Executor exec;
        Exec_DEFAULT(exec);
        Tokenizer_Tokenize(code, &code, &tok);
        Exec_execute(&exec, &tok);

        Tokenizer_Tokenize(code, &code, &tok);
        Exec_execute(&exec, &tok);


        Tokenizer_Tokenize(code, &code, &tok);
        Exec_execute(&exec, &tok);

        Tokenizer_Tokenize(code, &code, &tok);
        Exec_execute(&exec, &tok);

        Tokenizer_Tokenize(code, &code, &tok);
        Exec_execute(&exec, &tok);

        Tokenizer_Tokenize(code, &code, &tok);
        Exec_execute(&exec, &tok);

        return 0;
}
