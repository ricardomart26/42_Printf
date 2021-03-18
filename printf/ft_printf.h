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
	int p_zero;
	int p_align;
	int v_width;
	int	v_precision;
	char c;
	char *conv;
	int size_conv;
	int ret_count;
	int control; //Acrescentar no iniciar struct
	int new_precision;
	int	counter_precision;
	int counter_flags;
	int counter_words;

} sign_t;


// Para parar programa


// printf
int		print_until_perc(char *format, sign_t *signs);
void	start_loop(char *format, va_list args, sign_t *signs);
int		ft_printf(const char *format, ...);
int		size_per(char *format, sign_t *signs);
char	*ft_letter(va_list args, sign_t *signs);

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
char	*ft_convadress(long int adress);
char	*ft_convhexa(unsigned int decimal, int control);
char	*ft_convert_char(int inteiro);

// Check
void	init_struct(sign_t *signs);
void	precision(sign_t *signs, char *format, va_list args);
void	width(sign_t *signs, char *format, va_list args);
void	flags(sign_t *signs, char *format, va_list args);
void	star(sign_t *signs, va_list args);

// do
void	handle_signs(sign_t *signs, va_list args);
void	do_precision(sign_t *signs);
void	do_width(sign_t *signs);



#endif
