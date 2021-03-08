#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct signs
{
  int dot;
  int zero;
  int align;  
  int star;

} sign_t;

// printf
int number_per(char *format, int size);
int size_per(char *format);
int print_until_perc(char *format);
void basic_perc(va_list args, char *format, int size);
void start_loop(char *format, va_list args, int count_args);
int ft_printf(const char *format, ...);

// Validate
void see_signs(char *format, sign_t *signs, int size_perc);
int type(char c);
int sign(char c);

// utils
int	ft_isdigit(int c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int	ft_isalpha(int c);

// Convert
void convert_strings(va_list args);



#endif