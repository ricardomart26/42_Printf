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
	int p_dot;
	int p_zero;
	int p_align;
	int p_star;
	int p_width;
	int v_width;
	int v_dot;
	int v_star;
	char c;
} sign_t;


// Para parar programa


// printf
int		print_until_perc(char *format);
void	basic_perc(va_list args, char *format, int size);
char	*start_loop(char *format, va_list args, sign_t *signs);
int		ft_printf(const char *format, ...);
char	*ft_letter(va_list args, const char *format, sign_t *signs);

// Validate
void	see_signs(char *format, sign_t *signs, va_list args);
int		type(char c);
int		sign(char c);
int		valid_strchr(const char *s, int *i);
int		ft_checkvalid(const char *format);
int		number_per(char *format, int size);
int		size_per(char *format, sign_t *signs);

// utils
int		ft_isdigit(char c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_isalpha(int c);
void	ft_putnbr_fd(int n, int fd);
void	ft_revstr(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char *src);
int		ft_strlen(const char *str);

// Convert
char	*ft_unsigneditoa(unsigned int n);
char	*ft_itoa(int n);
void	ft_putchar(int i);
void	ft_putstr(char *str);
void	ft_parsing(va_list  args, const char *format, int i);
int		ft_unsignedlen(unsigned int n);
int		ft_intlen(int n);
char	*ft_strdup(char *src);
void	ft_revstr(char *str);
char	*ft_convhexa(unsigned int decimal, int control);
char	*ft_convaddr(void *ptr);
char	*ft_strchr(const char *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_convert_char(int inteiro);

// Check
void	precision(sign_t *signs, char *format, int *i, va_list args);
void	width(sign_t *signs, char *format, int *i, va_list args);
void	flags(sign_t *signs, char *format, va_list args);
// void	see_signs(char *format, sign_t *signs, char c, va_list args);

#endif
