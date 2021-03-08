#include <stdio.h>

typedef struct main
{
  int dot;
  int align;
  int star;
  int digit;

} main_t;

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void  see_signs(char *string, main_t temp)
{
  int c;

  c = 0;
  while (string[c])
  {
    if (string[c] == '.')
      temp.dot = 1;
    if (string[c] == '*')
      temp.star = 1;
    if (string[c] == '-')
      temp.align = 1;
    if (ft_isdigit(string[c]))
      temp.digit = 1;
    c++;
  }
}

int main(void)
{
  char *string = "Teste numero 1 . -";
  main_t temp;

  printf("%s\n", string);
  see_signs(string, temp);

  printf("star = %d\n", temp.star);
  printf("align = %d\n", temp.align);
  printf("dot = %d\n", temp.dot);
  printf("digit = %d\n", temp.digit);

  return (0);
}