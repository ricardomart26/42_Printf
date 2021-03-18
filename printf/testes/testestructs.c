#include <stdio.h>


typedef struct main
{
  int dot;
  int align;
  int star;
  int digit;

} main_t;

void  see_signs(char *string, main_t *temp);
int  init_struct(main_t *temp, char *string);

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int  init_struct(main_t *temp, char *string)
{
  temp->align = 0;
  temp->star = 0;
  temp->dot = 0;
  temp->digit = 0;
  printf("star = %d\n", temp->star);
  printf("align = %d\n", temp->align);
  printf("dot = %d\n", temp->dot);
  printf("digit = %d\n", temp->digit);

  see_signs(string, temp);
}

void  see_signs(char *string, main_t *temp)
{
  int c;

  c = 0;
  while (string[c])
  {
    if (string[c] == '.')
      temp->dot = 1;
    if (string[c] == '*')
      temp->star = 1;
    if (string[c] == '-')
      temp->align = 1;
    if (ft_isdigit(string[c]))
      temp->digit = 1;
    c++;
  }
}

int main(void)
{
  char *string = "Teste numero 1 . -";
  main_t temp;

  printf("%s\n", string);
  //see_signs(string, &temp);
  init_struct(&temp, string);
  printf("star = %d\n", temp.star);
  printf("align = %d\n", temp.align);
  printf("dot = %d\n", temp.dot);
  printf("digit = %d\n", temp.digit);

  return (0);
}