#ifndef FIRE_COMPILE_H
#define FIRE_COMPILE_H
//this header contains tools and methods for compiling or interpreting code

#include <stdio.h>
#include "CodeGen.h"
#include "FireMachine.h"

//compiles a string of Fire source code once.
void Compile_compile(char* source);

//compiles a string of Fire source code with a singular static state
void Compile_sCompile(char* source);




#endif
