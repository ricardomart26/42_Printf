#include <stdio.h>

void  printf_func()
{
  printf("\n\n PRINTF REAL \n\n");

  printf("%s\n", "ola tudo bem?");
  printf("%s\n%s\n", "ola tudo bem?", "sim e contigo?");
  printf("%s%s\n", "ola tudo", " bem?");
  printf("%s %s\n", "ola tudo", " bem?");
  printf("%5s\n", "ola tudo bem?");
  printf("%25s\n", "ola tudo bem?");
  printf("%.35s\n", "ola tudo bem?");
  printf("%16.23s\n", "ola tudo bem?");
  printf("%3.s\n", "ola tudo bem?");
  printf("%5.22s\n", "ola tudo bem?");
  printf("%22.5s\n", "ola tudo bem?");
  printf("%22.20s\n", "ola tudo bem?");
  printf("%-24s coisas a frente\n", "ola tudo bem?");
  printf("%-26.30s coisas a frente\n", "ola tudo bem?");
  printf("%-14s coisas a frente\n", "ola tudo bem?");
  printf("%-.23s coisas a frente\n", "ola tudo bem?");
  printf("%023s\n", "ola tudo bem?");
  printf("%012s\n", "ola tudo bem?");
  printf("%0.24s\n", "ola tudo bem?");
  printf("%0.12s\n", "ola tudo bem?");
  printf("%024.28s\n", "ola tudo bem?");
  printf("%028.24s\n", "ola tudo bem?");
  printf("%0.0s\n", "ola tudo bem?");
  
}

void  ft_printf_func()
{
  ft_printf("\n\n MEU PRINTF \n\n");

  ft_printf("%s\n", "ola tudo bem?");
  ft_printf("%s\n%s\n", "ola tudo bem?", "sim e contigo?");
  ft_printf("%s%s\n", "ola tudo", " bem?");
  ft_printf("%s %s\n", "ola tudo", " bem?");
  ft_printf("%5s\n", "ola tudo bem?");
  ft_printf("%25s\n", "ola tudo bem?");
  ft_printf("%.35s\n", "ola tudo bem?");
  ft_printf("%16.23s\n", "ola tudo bem?");
  ft_printf("%3.s\n", "ola tudo bem?");
  ft_printf("%5.22s\n", "ola tudo bem?");
  ft_printf("%22.5s\n", "ola tudo bem?");
  ft_printf("%22.20s\n", "ola tudo bem?");
  ft_printf("%-24s coisas a frente\n", "ola tudo bem?");
  ft_printf("%-26.30s coisas a frente\n", "ola tudo bem?");
  ft_printf("%-14s coisas a frente\n", "ola tudo bem?");
  ft_printf("%-.23s coisas a frente\n", "ola tudo bem?");
  ft_printf("%023s\n", "ola tudo bem?");
  ft_printf("%012s\n", "ola tudo bem?");
  ft_printf("%0.24s\n", "ola tudo bem?");
  ft_printf("%0.12s\n", "ola tudo bem?");
  ft_printf("%024.28s\n", "ola tudo bem?");
  ft_printf("%028.24s\n", "ola tudo bem?");
  ft_printf("%0.0s\n", "ola tudo bem?");
  
}

int main(void)
{
  printf_func();
  ft_printf_func(); 
}