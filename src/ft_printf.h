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
	int		zero;
	int		align;
	int		width;
	int		dot;
	int		cdot;
	char	c;
	char	*conv;
	int		size_c;
	int		temp_dot;
	int		words;
	int		cminus;
	int		negprec;
	int		max_value;
} sign_t;

// printf
int		print_until_perc(char *format, int *words);
void	start_loop(char *format, va_list args, sign_t *signs);
int		ft_printf(const char *format, ...);
int		size_per(char *fmt, char *c);
//void	free_needed(char *string, char c);
void	with_no_flags(va_list args, char *conv, int *words, char c);
void	with_flags(sign_t *st, char *fmt, va_list args);
// args
char	*get_arg(va_list args, char c, int *cminus, int *max);
void	do_arg(va_list args, sign_t *st);
// Validate
int		type(char c);
int		sign(char c);
int		invalid(char const *str);
// utils
int		ft_isdigit(char c);
void	ft_putstr(char *string, int *words);
char	*ft_strdup(char *src);
int		ft_strlen(const char *str);
int		ft_atoi(char *str);
void	ft_putchar(char c, int *words);
void	swap(char **string, int size, int *dot);
// Convert
char	*ft_unsigneditoa(unsigned long long n);
char	*ft_itoa(int n, int **cminus, int **max);
char	*ft_convadress(unsigned long long adress);
char	*ft_convhexa(unsigned int decimal, int control);
char	*ft_convert_char(int inteiro);
int		ft_intlen(int n);
// Check
void	init_struct(sign_t *signs);
void	see_precision(sign_t *signs, char *format, va_list args);
void	see_width(sign_t *signs, char *format, va_list args, int *c_signs);
void	flags(sign_t *signs, char *format, va_list args);

void	mult_char(char c, int *words, int size);
void	width(sign_t *st);
void	align(sign_t *st);

// int
void	align_int(sign_t *st);
void	specific_i(sign_t *st);
void	width_int(sign_t *st);
void	precision_inteiro(sign_t *st);
void	align_width(sign_t *st);


// Neg int
void	width_neg(sign_t *st);
void	specific_i_neg(sign_t *st);
void	zero_neg_width(sign_t *st);
void	negative_int(sign_t *st);
void	negative_align(sign_t *st);
void	precision_inteiro_neg(sign_t *st);


// Uint
void	specific_u(sign_t *st);
int		check_max_u_int(int size_c);
void	align_int_u(sign_t *st, int uintmax);
void	align_width_u(sign_t *st);
void	width_int_u(sign_t *st, int uintmax);


// Strings
void	precision_s(sign_t *st);
void 	specific_s(sign_t *st);
void 	specific_c(sign_t *st);


// outros
void 	specific_x(sign_t *st);
void	precision_inteiro_x(sign_t *st);
int		check_max_x_int(int size_c);
void	align_int_x(sign_t *st, int uintmax);
void	align_width_x(sign_t *st);
void	width_int_x(sign_t *st, int uintmax);

void 	specific_p(sign_t *st);
#endif
