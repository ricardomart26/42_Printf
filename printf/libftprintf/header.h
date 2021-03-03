#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdbool.h>

typedef struct DataTypes
{
  int inteiro;
  char character;
  char *str;
  unsigned int uInt;
  int size;
} Data;

bool dataType(char c);
bool buffer(char c1, char c2, char c3);
void cBuffer(char *str, int *size);
int intSize(int x);
char utoa(unsigned u, unsigned size);
void octal(unsigned int x);
void pointer(char *ptr);
int ft_printf(const char *, ...);
int count_args(char *str);
void Hexadecimal(unsigned int x);

#endif