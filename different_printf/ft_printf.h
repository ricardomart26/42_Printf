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
	int cminus;
	int width_c;

} sign_t;

// printf
int		print_until_perc(char *format, sign_t *signs);
void	start_loop(char *format, va_list args, sign_t *signs);
int		ft_printf(const char *format, ...);
int		size_per(char *format, sign_t *signs);
void	free_if_needed(sign_t *signs);
void	with_no_flags(va_list args, sign_t *st);
void	with_flags(sign_t *st, char *fmt, va_list args);

// args
char	*ft_get_arg(va_list args, sign_t *signs);
void	do_arg(va_list args, sign_t *st);

// Validate
int		type(char c);
int		sign(char c);
int		invalid(char const *str);

// utils
int		ft_isdigit(char c);
void	ft_putstr_fd(char *s, int fd, sign_t *st);
char	*ft_strdup(char *src);
int		ft_strlen(const char *str);
int		ft_atoi(char *str);
void	ft_putchar(char c, sign_t *st);
void	swap(sign_t *st);

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




void	if_width(sign_t *st);
void	if_precision(sign_t *st);
void	width_s_precision(sign_t *st);
void	if_align(sign_t *st);
void	width_b_precision(sign_t *st);
void	width_e_precision(sign_t *st);


// int
void	if_align_int(sign_t *st);
void 	specif_int(sign_t *st, va_list args);
void 	specif_uint(sign_t *st, va_list args);

// Strings
void	if_precision_s(sign_t *st);
void 	specif_s(sign_t *st, va_list args);
void	width_s_precision_s(sign_t *st);
void	width_e_precision_s(sign_t *st);
void 	specif_c(sign_t *st, va_list args);


// outros
void 	specif_x(sign_t *st, va_list args);
void 	specif_p(sign_t *st, va_list args);


#endif
