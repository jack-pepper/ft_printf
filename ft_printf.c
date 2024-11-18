/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:22:43 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/15 11:04:36 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/* 
 * Custom implementation of print_f().
 *
 * This version handles the following conversions and writes to stdout:
 *	%c: Prints a single character.
 *	%s: Prints a string (as defined by the common C convention).
 *	%p: Prints the void * pointer argument in hexadecimal (as if by %#x or %#lx) 
 *	%d: Prints a decimal (base 10) number.
 *	%i: Prints an integer in base 10.
 *	%u: Prints an unsigned decimal (base 10) number.
 *	%x: Prints a number in hexadecimal (base 16) lowercase format.
 *	%X: Prints a number in hexadecimal (base 16) uppercase format.
 *	%%: Prints a percent sign.
*/

int	main(void)
{
	int	whatever = 5;
	printf("Pt: %p \n", &whatever);
	int	*void_p = NULL;
	//	int	*whatever_p = &whatever;	
	printf("[PRINTF]%d [FT_PRINTF]%d \n", printf("%c\n", 'x'), ft_printf("%c\n", 'x'));
	printf("[PRINTF]%d [FT_PRINTF]%d \n", printf("%s\n", "One string"), ft_printf("%s\n", "One string"));
	printf("[PRINTF]%d [FT_PRINTF]%d \n", printf("%s - %s\n", "String 1", "String 2"), ft_printf("%s - %s\n", "String 1", "String 2"));

	printf("[PRINTF]%d [FT_PRINTF]%d \n", printf("%d\n", 1), ft_printf("%d\n", 1));
	printf("[PRINTF]%d [FT_PRINTF]%d \n", printf("%d\n", -12), ft_printf("%d\n", -12));
	printf("[PRINTF]%d [FT_PRINTF]%d \n", printf("%d - %d\n", -1234567, 777), ft_printf("%d - %d\n", -1234567, 777));
	
	printf("[PRINTF]%d [FT_PRINTF]%d \n", printf("%d\n", 1), ft_printf("%d\n", 1));
	printf("[PRINTF]%d [FT_PRINTF]%d \n", printf("%+d\n", 12), ft_printf("%+d\n", 12));
	printf("[PRINTF]%d [FT_PRINTF]%d \n", printf("% d\n% d\n", -1234567, 777), ft_printf("% d\n% d\n", -1234567, 777));

	printf("[PRINTF]%d [FT_PRINTF]%d \n", printf("pr %p\n", void_p), ft_printf("ft %p\n", void_p));
	printf("[PRINTF]%d [FT_PRINTF]%d \n", printf("pr %#X\n", 36453), ft_printf("ft %#X\n", 36453));
	printf("[PRINTF]%d [FT_PRINTF]%d \n", printf("pr %#x\n", 777), ft_printf("ft %#x\n", 777));
	printf("[PRINTF]%d [FT_PRINTF]%d \n", printf("pr %X\n", 15), ft_printf("ft %X\n", 15));
	printf("[PRINTF]%d [FT_PRINTF]%d \n", printf("pr %x\n", 0), ft_printf("ft %x\n", 0));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	B_writ;

	va_start(args, format);
	if (!format)
		return (-1);
	B_writ = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format = spec_conv(format, args, &B_writ);
		}
		else
		{
			write(1, &(*format), 1);
			B_writ++;
		}
		format++;
	}
	va_end(args);
	return (B_writ);
}

const char	*spec_conv(const char *format, va_list args, size_t *B_writ)
{	
	const char	*next_i;
	char		flags[10] = {}; // moduler en finalisation
	
	next_i = format + 1;
	while (*next_i == '#' || *next_i == ' ' || *next_i == '+')
	{
		if (*next_i == '#')
			flags[0] = '#';
		if (*next_i == ' ')
			flags[1] = ' ';
		if (*next_i == '+')
			flags[2] = '+';
		next_i++;
	}
	if (*next_i == 'd' || *next_i == 'i' || *next_i == 'u')
		spec_conv_num(next_i, args, flags, B_writ);
	else if (*next_i == 'p' || *next_i == 'x' || *next_i == 'X')
		spec_conv_hex(next_i, args, flags, B_writ);
	else if (*next_i == 's' || *next_i == 'c' || *next_i == '%')
		spec_conv_txt(next_i, args, B_writ);
	return (next_i);
}

void	spec_conv_num(const char *next_i, va_list args, char *flags, size_t *B_writ)
{
	int	current_arg;

	if (*next_i == 'i' || *next_i == 'd')
	{
		current_arg = va_arg(args, int);
		if (flags[1] == ' ' && current_arg >= 0 && flags[2] != '+')
		{
			*B_writ += ft_putchar_fd_count(' ', 1);
			*B_writ += ft_putnbr_fd_count(current_arg, 1);
		}
		else if (flags[2] == '+' && current_arg >= 0)
		{
			*B_writ += ft_putchar_fd_count('+', 1);
			*B_writ += ft_putnbr_fd_count(current_arg, 1);
		}
		else
			*B_writ += ft_putnbr_fd_count(current_arg, 1);
	}
	else if (*next_i == 'u')
		*B_writ += ft_putnbr_fd_count(va_arg(args, unsigned int), 1);
}

void	spec_conv_hex(const char *next_i, va_list args, char *flags, size_t *B_writ)
{
	char		*hex_value;

	hex_value = NULL;
	if (*next_i == 'p')
	{	
		hex_value = ft_itohex(hex_value, va_arg(args, unsigned long), 'p');
		*B_writ += ft_putstr_fd_count(hex_value, 1);
	}

	else if (*next_i == 'x' || *next_i == 'X')
	{
		if (flags[0] == '#')
			hex_value = ft_itohex(hex_value, va_arg(args, unsigned int), '#');
		else
			hex_value = ft_itohex(hex_value, va_arg(args, unsigned int), *next_i);
		*B_writ += ft_putstr_fd_count(hex_value, 1);
	}
	if (hex_value != NULL)
		free(hex_value);
}

void	spec_conv_txt(const char *next_i, va_list args, size_t *B_writ)
{
	if (*next_i == 'c')
	{
		*B_writ += ft_putchar_fd_count((char)va_arg(args, int), 1);
	}
	else if (*next_i == 's')
	{	
		*B_writ += ft_putstr_fd_count(va_arg(args, char *), 1);
	}
	else if (*next_i == '%')
	{
		*B_writ += ft_putchar_fd_count('%', 1);
	}
}

char	*ft_itohex(char *dest, unsigned long nb, char style)
{
	char		hex_value[20] = {};
	unsigned long	quotient;
	unsigned long	remainder;
	int		i;
	int		case_var;

	if (nb == 0)
		return (hex_handle_zero(hex_value, style));	
	hex_set_case(style, &case_var);
	quotient = nb;
	i = 0;
	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder >= 10 && remainder <= 15)
			hex_value[i] = (char)remainder + case_var;
		else if (remainder < 10)
			hex_value[i] = (char)remainder + '0';
		quotient = quotient / 16;
		i++;
	}
	hex_format_string(i, hex_value, style);
	dest = ft_strdup(hex_value);
	return (dest);
}

void	hex_set_case(char style, int *case_var)
{
	if (!case_var || !style)
		return ;
	if (style == 'X' || style == '#')
		*case_var = 'A' - 10;
	else
		*case_var = 'a' - 10;
}

char	*hex_handle_zero(char *hex_value, char style)
{
	char	*dest;
	int	i;

	i = 0;
	hex_value[i] = '0';
	if (style == 'p')
	{
		hex_value[i] = '(';
		hex_value[i + 1] = 'n';
		hex_value[i + 2] = 'i';
		hex_value[i + 3] = 'l';
		hex_value[i + 4] = ')';
		i = 4;
	}
	else if (style == '#')
	{
		hex_value[i + 1] = 'X';
		hex_value[i + 2] = '0';
		i = 2;
	}
	hex_value[i + 1] = '\0';
	dest = ft_strdup(hex_value);
	return (dest);
}

char	*hex_format_string(int i, char *hex_value, char style)
{
	if (style == 'p' || style == '#')
	{
		if (style == 'p')
			hex_value[i] = 'x';
		else if (style == '#')
			hex_value[i] = 'X';
		hex_value[i + 1] = '0';	
	}
	ft_strrev(hex_value);
	hex_value[i + 2] = '\0';
	return (hex_value);
}

size_t	ft_putchar_fd_count(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

size_t	ft_putstr_fd_count(char *s, int fd)
{
	size_t  i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
	return (i);
}

size_t	ft_putnbr_fd_count(int n, int fd)
{
	size_t	i;

	i = 0;
	if (n == -2147483648)
	{
		i += ft_putstr_fd_count("-2147483648", fd);
		return (i);
	}
	if (n < 0)
	{
		i += ft_putchar_fd_count('-', fd);
		n = -n;
	}
	if (n > 9)
	{
		i += ft_putnbr_fd_count(n / 10, fd);
	}
	i += ft_putchar_fd_count((n % 10) + '0', fd);
	return (i);
}
