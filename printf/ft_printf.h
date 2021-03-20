#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>

typedef struct signs
{
	int zero;
	int align;
	int width;
	int	dot;
	char c;
	char *conv;
	int size_c;
	int temp_dot;
	int	c_dot;
	int c_signs;
	int words;
	int edge_s;
} sign_t;

// printf
int		print_until_perc(char *format, sign_t *signs);
void	start_loop(char *format, va_list args, sign_t *signs);
int		ft_printf(const char *format, ...);
int		size_per(char *format, sign_t *signs);
char	*ft_get_arg(va_list args, sign_t *signs);
void	free_if_needed(sign_t *signs);
void	with_no_flags(va_list args, sign_t *st);
char	*ft_get_arg(va_list args, sign_t *st);

// Validate
int		type(char c);
int		sign(char c);
int		invalid(char const *str);

// utils
int		ft_isdigit(char c);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(char *src);
int		ft_strlen(const char *str);
int		ft_atoi(char *str);

// Convert
char	*ft_unsigneditoa(unsigned int n);
char	*ft_itoa(int n);
char	*ft_convadress(unsigned long adress);
char	*ft_convhexa(unsigned int decimal, int control);
char	*ft_convert_char(int inteiro);
int		ft_intlen(int n);


// Check
void	init_struct(sign_t *signs);
void	precision(sign_t *signs, char *format, va_list args);
void	width(sign_t *signs, char *format, va_list args);
void	flags(sign_t *signs, char *format, va_list args);
void	star(sign_t *signs, va_list args);
void	with_flags(sign_t *st, char *fmt, va_list args);

// do
void	handle_signs(sign_t *st);
void	middle_man(sign_t *signs, va_list args);
void	do_precision(sign_t *signs);
void	do_width(sign_t *signs);
void	if_width_or_precision(sign_t *st);
void	if_align(sign_t *st);
void	swap(sign_t *st);

#endif
