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

#include "libft.h"
#include <stdarg.h>
/* 
 * Custom implementation of print_f().
 *
 * This version handles the following conversions and writes to stdout:
 *	%c: Prints a single character.
 *	%s: Prints a string (as defined by the common C convention).
 *	%p:
 *	%d: Prints a decimal (base 10) number.
 *	%i: Prints an integer in base 10.
 *	%u: Prints an unsigned decimal (base 10) number.
 *	%x: Prints a number in hexadecimal (base 16) lowercase format.
 *	%X: Prints a number in hexadecimal (base 16) uppercase format.
 *	%%: Prints a percent sign.
*/


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

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*flags_set;

	flags_set = "# +";
	// Init list
	va_start(args, format);
	if (!format)
		return (-1);
	va_arg(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			manage_conv_spec(format, args, flags_set);
		}
		else
		{
			write(1, &(*format), 1);
		}
		format + 1; // or more if flags...
	}
	// Clean list
	va_end(args);
	return (// total of char returned with the null byte);

}

XXX	manage_conv_spec(char *format, va_list args, char *flags_set)
{
	char *next_i;

	next_i = format + 1;
	/*if (*next_i == xXXXX) // is_in_set
	{
		va_arg(args, xx)
	}
	*/
	if (*next_i == 'c')
		va_arg(argc, char);
	/*
	else if (*next_i == 's')
	{
	//
	}
	else if (*next_i == 'd')
	{
	//
	}
	else if (*next_i == 'i')
	{
	//
	}
	else if (*next_i == 'p')
	{
	//
	}
	else if (*next_i == 'u')
	{
	}
	else if (*next_i == 'x')
	{
	}
	else if (*next_i == 'X')
	{
	}
	else if (*next_i == '%')
	{
	}
	*/

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
}

XXX	manage_flags();
{

	// The character % is followed by zero or more of the following flags:
	// NB: %%?

BONUS: Manage all the following flags: # (space) and +

	if (*param + 1 == '#')
	/* The value should be converted to an "alternate form". 
		For x and X conversions, a nonzero result has the string "0x" (or "0X" for X conversions) prepended to it.  		For other conversions of this project, the result is undefined.
	*/

	if (*param + 1 == ' ')
	/* (a  space)  A blank should be left before a positive number (or empty string) produced by a signed con‐
              version.
	*/

	if (*param + 1 == '+')
	/* A sign (+ or -) should always be placed before a number produced by a signed conversion.  By default, a
              sign is used only for negative numbers.  A + overrides a space if both are used.
        */	

BONUS: Manage any combination of the following flags: '-0.' and the field minimum width under all conversions

	if (*param + 1 == '0')
	/* The value should be zero padded.  For d, i, o, u, x, X, a, A, e, E, f, F, g,  and  G  conversions,  the
              converted value is padded on the left with zeros rather than blanks.  If the 0 and - flags both appear,
              the 0 flag is ignored.  If a precision is given with a numeric conversion (d, i, o, u, x, and X), the 0
              flag is ignored.  For other conversions, the behavior is undefined.
	*/
	if (*param + 1 == '-')
	/* The  converted  value  is  to be left adjusted on the field boundary.  (The default is right justifica‐
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
*/

}
