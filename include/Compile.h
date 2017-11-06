#ifndef FIRE_COMPILE_H
#define FIRE_COMPILE_H
//this header contains tools and methods for compiling or interpreting code

#include <stdio.h>
#include "CodeGen.h"
#include "FireMachine.h"

#define Compile_PROMPT "fire> "
#define Compile_REPL_BSIZE 500

//compiles a string of Fire source code once.
void Compile_compile(char* source);

//compiles a string of Fire source code with a singular static state
void Compile_sCompile(char* source);

//begins an interactive repl loop
void Compile_repl();

//help function for printing help instructions
void Compile_help();


#endif
