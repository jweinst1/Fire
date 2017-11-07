# Fire

`*The Reactive Programming Language*`

## Intro

Fire is a programming language based around the concepts of reactive programming, streams, and data processing. It's a highly portable, fast, and simple to learn language that lets you do anything with data. The linear, readable syntax is designed to be a modern programmer's best friend.

Since Fire does not use nested structures, it can be translated directly into byte code, without any parsing, abstract syntax trees, or any of the other features a traditional compiler needs to run code. Fire also doesn't have a virtual machine, the bytecode is used to call methods directly on a binary stream.

## Status

The first Fire development build is complete, with a limited set of functionality.
This build is highly subject to changes in syntax and architecture.

## Usage

Fire's compiler is written in C and highly portable to almost any platform.

To build Fire, you can run the following in your shell

```
make all
```

This will produce an executable in the /bin folder of your directory.

Or you can download the executables under the releases tab of this repo.

### Command Line

The `Fire` executable currently takes two arguments:

#### `-i`: Turns on the interactive repl.

*Example*:

```
$ ./bin/Fire -i
fire> rng 10 -> out
[0 1 2 3 4 5 6 7 8 9 ]
fire> exit
```


#### `-h`: Prints out the help guide.

## Language Guide

### Printing Data
-----------------------------------
##### out:
prints the current stream and it's data.

```
fire> push 5 -> push 1 -> out
[5 1 ]
```

### Adding Data
-----------------------------------
##### push (number):
pushes one number onto end of stream.

```
fire> push 3 -> push 1 -> out
[3 1 ]
```

##### rng (n):
pushes a stream of numbers from zero to n onto the stream.

```
fire> rng 5 -> push 4 -> out
[0 1 2 3 4 4 ]
```

### Reducing Data
-----------------------------------
##### `{+}`:
Sums all the numbers in the stream and store the result at the front.

```
fire> rng 4 -> {+} -> out
[6 ]
```

##### `{-}`:
Subtracts all the numbers in the stream and store the result at the front.

```
fire> rng 4 -> out -> {-} -> out
[0 1 2 3 ]
[-6 ]
```

##### `{*}`:
Multiplies all the numbers in the stream and store the result at the front.

##### `{/}`:
Divides all the numbers in the stream and store the result at the front.


### Mapping Data
-----------------------------------
##### `+` (number):
Adds some number to all numbers in the stream.

```
fire> rng 4 -> out -> + 2 -> out
[0 1 2 3 ]
[2 3 4 5 ]
```

@ - (number): Subtracts some number from all numbers in the stream.
@ * (number): Multiplies each number in the stream.
@ / (number): Divides each number in the stream.
@ % (number): Calculates the remainder of each number of the stream by a number.
@ floor: Calculates and maps the floor of each number in the stream
- ex:
fire> rng 6 -> sin -> out -> floor -> out
[0 0.841471 0.909297 0.141120 -0.756802 -0.958924 ]
[0 0 0 0 -1 -1 ]
@ cos: Calculates and maps the cos of each number in the stream
@ sin: Calculates and maps the sin of each number in the stream
@ log: Calculates and maps the log(e) of each number in the stream
@ exp: Calculates and maps the (e)exp power of each number in the stream

### Filtering Data
-----------------------------------
All filtering expressions in Fire begin with an 'if' keyword.
 Any element in the stream which holds false for the expression is removed from the string.

@ if == (number): Filters out all numbers not equal to (number) in the stream.
@ if != (number): Filters out all numbers equal to (number) in the stream.
@ if > (number): Filters out all numbers greater than (number) in the stream.
- ex:
fire> rng 20 -> if > 5 -> out
[6 7 8 9 10 11 12 13 14 15 16 17 18 19 ]
@ if < (number): Filters out all numbers less than (number) in the stream.
