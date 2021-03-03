#include <stdio.h>

void sum3To5Multiples(int *x, int m)
{
  int c = 0;
  int array;

  while (c < m)
  {
    if (c == *x)
    {
      array += c;
      *x += 3;
    }
    else if (c == *x)
    {
      
    }
    
    c++;
  }
  c = 0;
  while (c < m)
  {
    array += c;
    c += 5;
  }
  *x = array;
}

int main(void)
{
  int x = 0;
  int m = 1000;

  sum3To5Multiples(&x, m);
  printf("%d", x);
}