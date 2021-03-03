#include <unistd.h>
#include <stdio.h>

int main()
{
  char c = '4';
  char *ptr = &c;
  char *str;
  int i;

  i = 0;
  str = "O ricardo";
  printf("%s\n", str);
  while (ptr[i])
  {
    printf("%s\n", str);
    *str = ptr[i];
    i++;
    *str++;
  }
  printf("%s\n", str);
  write(1, &c, 1);
  write(1, *&ptr, 1);

  return (0);
}