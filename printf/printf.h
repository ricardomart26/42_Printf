#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>


typedef struct signs
{
  int dot;
  int zero;
  int align;
  int star;

} sign_t;

// Para parar programa


// printf
int number_per(char *format, int size);
int size_per(char *format);
int print_until_perc(char *format);
void basic_perc(va_list args, char *format, int size);
void start_loop(char *format, va_list args);
int ft_printf(const char *format, ...);

// Validate
void see_signs(char **format, sign_t *signs, int size_perc);
int type(char c);
int sign(char c);
int	valid_strchr(const char *s, int *i);
int	ft_checkvalid(const char *format);


// utils
int	ft_isdigit(char c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int	ft_isalpha(int c);
void	ft_putnbr_fd(int n, int fd);
void	ft_revstr(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char *src);
size_t	ft_strlen(const char *str);




// Convert
char	*ft_unsigneditoa(unsigned int n);
char	*ft_itoa(int n);
void	ft_putchar(int i);
void	ft_putstr(char *str);
void    ft_parsing(va_list  args, const char *format, int i);
int		ft_unsignedlen(unsigned int n);
int		ft_intlen(int n);
char	*ft_strdup(char *src);
size_t	ft_strlen(const char *str);
void	ft_revstr(char *str);
char	*ft_convhexa(unsigned int decimal, int control);
char	*ft_convaddr(void *ptr);
char	*ft_strchr(const char *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char *ft_convert_char(int inteiro);

#endif
