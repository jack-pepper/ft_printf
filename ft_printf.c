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


// I must pass next_i in every procedure of spec_conv. Maybe with another local variable?



#include "libft.h"
#include <stdarg.h>
#include <stdio.h>
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

int	ft_printf(const char *format, ...);
const char	*spec_conv(const char *format, va_list args, size_t *B_writ);
void	spec_conv_num(const char *format, va_list args, char *flags, size_t *B_writ);
void	spec_conv_hex(const char *format, va_list args, char *flags, size_t *B_writ);
void	spec_conv_txt(const char *format, va_list args, size_t *B_writ);
size_t	ft_putchar_fd_count(char c, int fd);
size_t	ft_putstr_fd_count(char *s, int fd);
size_t	ft_putnbr_fd_count(int n, int fd);
char	*ft_itohex(char *dest, unsigned long nb, char style);
void	hex_set_case(char style, int *case_var);
char	*hex_handle_zero(char *hex_value, char style);
char	*hex_format_string(int i, char *hex_value, char style);
char	*ft_strrev(char *str);

/* Format of the format string
       The format string is a character string, beginning and ending in its initial shift state, if any.  The  format
       string  is composed of zero or more directives: ordinary characters (not %), which are copied unchanged to the
       output stream; and conversion specifications, each of which results in fetching zero or more subsequent  argu‐
       ments.   Each conversion specification is introduced by the character %, and ends with a conversion specifier.
       In between there may be (in this order) zero or more flags, an optional minimum field width, an optional  pre‐
       cision and an optional length modifier.

       The  arguments must correspond properly (after type promotion) with the conversion specifier.  By default, the
       arguments are used in the order given, where each '*' (see Field width and Precision below) and  each  conver‐
       sion  specifier  asks  for  the next argument (and it is an error if insufficiently many arguments are given).
       One can also specify explicitly which argument is taken, at each place where an argument is required, by writ‐
       ing "%m$" instead of '%' and "*m$" instead of '*', where the decimal integer m denotes the position in the ar‐
       gument list of the desired argument, indexed starting from 1.  Thus,

           printf("%*d", width, num);

       and

           printf("%2$*1$d", width, num);

       are equivalent.  The second style allows repeated references to the same argument.  The C99 standard does  not
       include  the style using '$', which comes from the Single UNIX Specification.  If the style using '$' is used,
       it must be used throughout for all conversions taking an argument and all width and precision  arguments,  but
       it  may  be mixed with "%%" formats, which do not consume an argument.  There may be no gaps in the numbers of
       arguments specified using '$'; for example, if arguments 1 and 3 are specified, argument 2 must also be speci‐
       fied somewhere in the format string.

       For  some  numeric  conversions  a radix character ("decimal point") or thousands' grouping character is used.
       The actual character used depends on the LC_NUMERIC part of the locale.  (See setlocale(3).)  The POSIX locale
       uses '.' as radix character, and does not have a grouping character.  Thus,

           printf("%'.2f", 1234567.89);

       results in "1234567.89" in the POSIX locale, in "1234567,89" in the nl_NL locale, and in "1.234.567,89" in the
       da_DK locale.
      */

int	main(void)
{
	int	whatever = 5;
	printf("Pt: %p \n", &whatever);
	int	*void_p = NULL;
	//	int	*whatever_p = &whatever;
/*	
	printf("[PRINTF]%d [FT_PRINTF]%d \n", printf("%c\n", 'x'), ft_printf("%c\n", 'x'));
	printf("[PRINTF]%d [FT_PRINTF]%d \n", printf("%s\n", "One string"), ft_printf("%s\n", "One string"));
	printf("[PRINTF]%d [FT_PRINTF]%d \n", printf("%s - %s\n", "String 1", "String 2"), ft_printf("%s - %s\n", "String 1", "String 2"));
*/

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
	//printf("Input string before format: %s\n", hex_value); // Debug
	hex_format_string(i, hex_value, style);
	//printf("Input string before ft_strdup: %s\n", hex_value); // Debug	
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

/*
 * - c: converted to an unsigned char and the resulting char is written

 * - s: the const char * arg is expected to be a pointer to an array of character type (pointer to a string)
 *    Characters from the array are written up to (but not including) a terminating null byte ('\0').
 *    [BONUS: if a precision is specified, no more than the number specified are written.  
 *    If a precision is given, no null byte need be present; if the precision is not specified,  or  is 
 *    greater than the size of the array, the array must contain a terminating null byte.]
 *   
 *  - d, i: The int argument is converted to signed decimal notation. 
 *    If any, the precision gives the minimum number of digits that must appear: if the converted value
 *    requires fewer digits, it is padded on the left with zeros. The default precision is 1. When 0 is printed
      with an explicit precision 0, the output is empty.
 *  
 * - p: The void * pointer argument is printed in hexadecimal (as if by %#x or %#lx).
 * 
 * - u: The unsigned int argument is converted to unsigned decimal
 * - x: The unsigned int argument is converted to unsigned hexadecimal. The letters abcdef are used for x conversions
 * - X: The unsigned int argument is converted to unsigned hexadecimal. The letters ABCDEF are used for X conversions
 * === u, x, X: The precision, if any, gives the minimum number of digits that must appear; 
 *                if  the converted  value  requires fewer digits, it is padded on the left with zeros.  
 *          The default precision is 1.  When 0 is printed with an explicit precision 0, the output is empty.
 *
 * - %%	A '%' is written.  No argument is converted.  The complete conversion specification is '%%'.
*/

/* XXX	manage_flags();
{
reater than the size of the array, the array must contain a terminating null byte.]
 *   



BONUS: Manage any combination of the following flags: '-0.' and the field minimum width under all conversions

	if (*param + 1 == '0')
	* The value should be zero padded.  For d, i, o, u, x, X, a, A, e, E, f, F, g,  and  G  conversions,  the
              converted value is padded on the left with zeros rather than blanks.  If the 0 and - flags both appear,
              the 0 flag is ignored.  If a precision is given with a numeric conversion (d, i, o, u, x, and X), the 0
              flag is ignored.  For other conversions, the behavior is undefined.

	if (*param + 1 == '-')
 The  converted  value  is  to be left adjusted on the field boundary.  (The default is right justifica‐
              tion.)  The converted value is padded on the right with blanks, rather than on the left with blanks  or
              zeros.  A - overrides a 0 if both are given.
	*/

/* gerer la taille minimum du champ - Field width
       An optional decimal digit string (with nonzero first digit) specifying a minimum field  width.   If  the  con‐
       verted  value  has fewer characters than the field width, it will be padded with spaces on the left (or right,
       if the left-adjustment flag has been given).  Instead of a decimal digit string one may  write  "*"  or  "*m$"
       (for some decimal integer m) to specify that the field width is given in the next argument, or in the m-th ar‐
       gument, respectively, which must be of type int.  A negative field width is taken as a '-' flag followed by  a
       positive  field width.  In no case does a nonexistent or small field width cause truncation of a field; if the
       result of a conversion is wider than the field width, the field is expanded to contain the conversion result.
*/

/* gerer la precision - Precision
       An optional precision, in the form of a period ('.')  followed by an optional decimal digit  string.   Instead
       of  a  decimal digit string one may write "*" or "*m$" (for some decimal integer m) to specify that the preci‐
       sion is given in the next argument, or in the m-th argument, respectively, which must be of type int.  If  the
       precision  is  given  as just '.', the precision is taken to be zero.  A negative precision is taken as if the
       precision were omitted.  This gives the minimum number of digits to appear for d, i, o, u, x,  and  X  conver‐
       sions, the number of digits to appear after the radix character for a, A, e, E, f, and F conversions, the max‐
       imum number of significant digits for g and G conversions, or the maximum number of characters to  be  printed
       from a string for s and S conversions.
reater than the size of the array, the array must contain a terminating null byte.*/   




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

size_t    ft_putnbr_fd_count(int n, int fd)
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
