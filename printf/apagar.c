// void basic_perc(va_list args, char *format, int size)
// {
// 	int c;

// 	c = 0;
// 	if (format[c] == '%' && format[c - 1] == '%')
// 		ft_putchar_fd('%', 1);
// 	if (format[c] == '%' && format[size - 1] == 's')
// 		convert_strings(args);
// 	if (format[c] == '%' && format[size - 1] == 'd')
// 		convert_int(args);
// }


// void see_signs(char *format, sign_t *signs, char c, va_list args)
// {
// 	int i;
// 	int save_number;
// 	i = 1;
// 	while (!(type(format[i])))
// 	{
// 		if (format[i] == '.')
//			signs->p_dot = i;
// 		if (format[i] == '*')
// 			signs->p_star = i;
// 		if (format[i] == '0')
// 			signs->p_zero = i;
// 		else if (ft_isdigit(format[i]))
// 			signs->p_zero = i;
// 		i++;
// 	}
// 	return (signs_trasnform(format, signs, c, args));
// }

// int		ft_printit(char *temp, sign_t *signs)
// {
// 	int size;

// 	size = ft_strlen(temp);

// }



// start loop

			// if (signs->control != 1)
			// {
			// 	signs->conv = ft_letter(args, format, *signs);
			// 	signs->size_conv = ft_strlen(signs->conv);
			// 	handle_signs(*signs);
			// }

// int number_per(char *format, int size)
// {
// 	int counter;
// 	int c;

// 	c = 0;
// 	counter = 0;

// 	while (format[c] != '\0')
// 	{
// 		if (format[c] == '%')
// 		{
// 			c++;
// 			if ((invalid((char *)format)))
// 				return (0);
// 			counter++;
// 		}
// 		c++;
// 	}
// 	return (counter);
// }



// void	star_after_precision(sign_t *signs, char *format, int *i, va_list args)
// {

// }

// int	validate_signs(char *format, sign_t signs)
// {
// 	return (0);
// }

