CC = gcc
CCPP = g++
CPPFLAGS =	-std=c++11
CPPLINK = -lstdc++
INC_DIR = include

C_FILES := $(wildcard src/*/*.c)
OBJ_FILES := $(patsubst src/%,lib/%,$(C_FILES:.c=.o))
LD_FLAGS :=
CC_FLAGS := -c -Wall -I$(INC_DIR)

bin/Fire: $(OBJ_FILES) ; $(CC) $(LD_FLAGS) -o $@ $^

lib/%.o: src/%.c
	    mkdir -p $(dir $@)
	    $(CC) $(CC_FLAGS) -c -o $@ $<
