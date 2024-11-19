/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:22:43 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/19 12:04:48 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/* 
 * This set of functions analyses ft_printf's args and outputs them depending
 * on the flags (#, <space> or +). While writing, it will update the number
 * of bytes written through the b_writ pointer.
 *
*/

const char	*ft_spec_conv(const char *format, va_list args, size_t *b_writ)
{
	const char	*next_i;
	char		flags[10];

	ft_memset(flags, 0, sizeof(flags));
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
		conv_num(next_i, args, flags, b_writ);
	else if (*next_i == 'p' || *next_i == 'x' || *next_i == 'X')
		conv_hex(next_i, args, flags, b_writ);
	else if (*next_i == 's' || *next_i == 'c' || *next_i == '%')
		conv_txt(next_i, args, b_writ);
	return (next_i);
}

void	conv_num(const char *next_i, va_list args, char *flags, size_t *b_writ)
{
	int	current_arg;

	if (*next_i == 'i' || *next_i == 'd')
	{
		current_arg = va_arg(args, int);
		if (flags[1] == ' ' && current_arg >= 0 && flags[2] != '+')
		{
			*b_writ += ft_putchar_fd_count(' ', 1);
			*b_writ += ft_putnbr_fd_count(current_arg, 1);
		}
		else if (flags[2] == '+' && current_arg >= 0)
		{
			*b_writ += ft_putchar_fd_count('+', 1);
			*b_writ += ft_putnbr_fd_count(current_arg, 1);
		}
		else
			*b_writ += ft_putnbr_fd_count(current_arg, 1);
	}
	else if (*next_i == 'u')
		*b_writ += ft_putnbr_fd_count(va_arg(args, unsigned int), 1);
}

void	conv_hex(const char *next_i, va_list args, char *flags, size_t *b_writ)
{
	int		current_arg;
	char	*hex_value;

	hex_value = NULL;
	if (*next_i == 'p')
	{
		current_arg = va_arg(args, unsigned long);
		hex_value = ft_itohex(hex_value, current_arg, 'p');
		*b_writ += ft_putstr_fd_count(hex_value, 1);
	}
	else if (*next_i == 'x' || *next_i == 'X')
	{
		current_arg = va_arg(args, unsigned int);
		if (flags[0] == '#')
			hex_value = ft_itohex(hex_value, current_arg, '#');
		else
			hex_value = ft_itohex(hex_value, current_arg, *next_i);
		*b_writ += ft_putstr_fd_count(hex_value, 1);
	}
	if (hex_value != NULL)
		free(hex_value);
}

void	conv_txt(const char *next_i, va_list args, size_t *b_writ)
{
	if (*next_i == 'c')
	{
		*b_writ += ft_putchar_fd_count((char)va_arg(args, int), 1);
	}
	else if (*next_i == 's')
	{
		*b_writ += ft_putstr_fd_count(va_arg(args, char *), 1);
	}
	else if (*next_i == '%')
	{
		*b_writ += ft_putchar_fd_count('%', 1);
	}
}
