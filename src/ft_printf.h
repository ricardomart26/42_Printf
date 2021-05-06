#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>

typedef struct s_signs
{
	int		zero;
	int		align;
	int		width;
	int		dot;
	char	c;
	char	*conv;
	int		size_c;
	int		temp_dot;
	int		words;
	int		cminus;
	int		negprec;
	int		negwidth;
	int		max_value;
	int		index;
}		t_sign;

int		print_until_perc(char *format, int *words);
void	start_loop(char *format, va_list args, t_sign *signs);
int		ft_printf(const char *format, ...);
int		size_per(char *fmt, char *c);
void	with_no_flags(va_list args, t_sign *st, char *fmt);
void	with_flags(t_sign *st, char *fmt, va_list args);
char	*get_arg(va_list args, char c, int *cminus, int *max);
void	do_arg(va_list args, t_sign *st);
int		type(char c);
int		sign(char c);
int		invalid(char const *str);
int		ft_isdigit(char c);
void	ft_putstr(char *string, int *words);
char	*ft_strdup(char *src);
int		ft_strlen(const char *str);
int		ft_atoi(char *str);
void	ft_putchar(char c, int *words);
void	swap(char **string, int size, int *dot);
char	*ft_unsigneditoa(unsigned long long n);
char	*ft_itoa(int n, int **cminus, int **max);
char	*ft_convadress(unsigned long long adress);
char	*ft_convhexa(unsigned int decimal, int control);
char	*ft_convert_char(int inteiro);
int		ft_intlen(int n);
void	init_struct(t_sign *signs);
void	see_precision(t_sign *signs, char *format, va_list args);
void	see_width(t_sign *signs, char *format, va_list args, int *c_signs);
void	flags(t_sign *signs, char *format, va_list args);
void	mult_char(char c, int *words, int size);
void	width(t_sign *st);
void	align_int(t_sign *st);
void	specific_i(t_sign *st);
void	width_int(t_sign *st);
void	precision_inteiro(t_sign *st);
void	align_width(t_sign *st);
void	special_case(t_sign *st);
void	width_neg(t_sign *st);
void	specific_i_neg(t_sign *st);
void	zero_neg_width(t_sign *st);
void	negative_int(t_sign *st);
void	negative_align(t_sign *st);
void	precision_inteiro_neg(t_sign *st);
void	specific_u_x(t_sign *st);
void	align_int_u(t_sign *st);
void	align_width_u(t_sign *st);
void	width_int_u(t_sign *st);
void	specific_s(t_sign *st);
void	specific_c(t_sign *st);
void	percentagem(t_sign *st);
void	width_p(t_sign *st);
void	specific_p(t_sign *st);
void	precision_inteiro_p(t_sign *st);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
