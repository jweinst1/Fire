#include "stdio.h"
#include "Tokenizer.h"

int main( int argc, char *argv[] )
{
        const char* code = "  \n\n  \n  56";
        char** marker = &code;
        Token tok = {0};
        Tokenizer_Tokenize(code, marker, &tok);
        printf("%f\n", tok.val.number);
        return 0;
}
