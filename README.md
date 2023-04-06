# Project Overview #

42_Printf is a project that requires the implementation of the printf function in C. The printf function is a powerful function that allows for formatted printing of text, similar to the printf function in the C standard library.

The goal of the project is to implement the printf function from scratch, without using the standard library functions.

## How to Use ##

To use this project, simply clone this repository and navigate to the root directory. From there, you can compile the program by running make.

Once compiled, you can use the ft_printf function just like the standard printf function. Here is an example:

```c

#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "world");
    return (0);
}

```

This will print "Hello, world!" to the console.

Supported Format Specifiers

The ft_printf function supports the following format specifiers:

| Format Specifier | Description               |
| ---------------- | ------------------------- |
| `%c`               | character                 |
| `%s`               | string                    |
| `%p`               | pointer address           |
| `%d`, `%i`           | signed decimal integer    |
| `%u`               | unsigned decimal integer  |
| `%x`, `%X`           | hexadecimal integer       |


The function also supports the following flags:

| Flag | Description         |
| ---- | ------------------- |
| `-`    | left-justify        |
| `0`    | zero-pad            |
| `.`    | precision           |
| `*`    | width or precision  |
| `+`  | Prefix a plus sign for positive signed numbers |