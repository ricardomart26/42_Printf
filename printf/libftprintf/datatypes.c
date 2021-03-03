#include "header.h"

void Hexadecimal(unsigned int x)
{
  char hexa[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
  char temp;

  if (x < 16)
    write(1, &hexa[x], 1);
  while (x > 0)
  {
    temp = x / 16 - '0'; // 7
    write(1, &hexa[temp], 1);
    temp = x % 16 - '0';
    write(1, &hexa[temp], 1);
  }
}

void octal(unsigned int x)
{
  char octal[8] = {'0', '1', '2', '3', '4', '5', '6', '7'};
  char temp;

  if (x < 8)
    write(1, &octal[x], 1);
  while (x > 0)
  {
    temp = x / 8 - '0'; // 7
    write(1, &octal[temp], 1);
    temp = x % 8 - '0';
    write(1, &octal[temp], 1);
  }
}

char utoa(unsigned u, unsigned size)
{
  int c;
  int j;
  char *temp;
  char *str;

  c = 0;
  while (u > 0)
  {
    temp[c] = u % 10 + '0';
    u /= 10;
    c++;
  }
  while (c > 0)
  {
    str[j] = temp[c];
    j++;
    c--;
  }
  return (str);
}

void pointer(char *ptr)
{
  char *temp;
  int c;

  c = 0;
  *temp = &ptr;
  while (temp != '\0')
  {
    write(1, &temp[c], 1);
    c++;
  }
}

int intSize(int x)
{
  int c;

  c = 0;

  if (x < 10)
    return (1);
  while (x >= 10)
  {
    x /= 10;
    c++;
  }
  return (c);
}
