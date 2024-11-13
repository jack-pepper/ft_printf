#include "libft.h"

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
//
//
	while (*param)
	{
		if (*param == '%')
			symbol_manager_percent();
		if (*param == '#')
			symbol_manager_hash();



	ft_putstr(XXX);
/*RETURN VALUE
		return ([NUMBER OF CHARACTERS PRINTED, EXCLUDING THE TERMINATING NULL BYTE!]); // if all good
		return (-1); // If output error encounteredi
*/
}

/* PAS de gestion de buffer */

/* Conversions : sSpdDioOuUxXcC
Conversion specifiers
       A character that specifies the type of conversion to be applied.  The conversion specifiers and their meanings
       are:

       d, i   The  int  argument  is  converted to signed decimal notation.  The precision, if any, gives the minimum
              number of digits that must appear; if the converted value requires fewer digits, it is  padded  on  the
              left with zeros.  The default precision is 1.  When 0 is printed with an explicit precision 0, the out‐
              put is empty.

	D ??? O ??? U ??? X ??? 

       o, u, x, X
              The unsigned int argument is converted to unsigned octal (o), unsigned decimal (u), or  unsigned  hexa‐
              decimal (x and X) notation.  The letters abcdef are used for x conversions; the letters ABCDEF are used
              for X conversions.  The precision, if any, gives the minimum number of digits that must appear; if  the
              converted  value  requires fewer digits, it is padded on the left with zeros.  The default precision is
              1.  When 0 is printed with an explicit precision 0, the output is empty.

       c      If no l modifier is present, the int argument is converted to an unsigned char, and the resulting char‐
              acter  is written.  If an l modifier is present, the wint_t (wide character) argument is converted to a
              multibyte sequence by a call to the wcrtomb(3) function, with a conversion state starting in  the  ini‐
              tial state, and the resulting multibyte string is written.

       s      If no l modifier is present: the const char * argument is expected to be a pointer to an array of char‐
              acter type (pointer to a string).  Characters from the array are written up to (but  not  including)  a
              terminating  null byte ('\0'); if a precision is specified, no more than the number specified are writ‐
              ten.  If a precision is given, no null byte need be present; if the precision is not specified,  or  is
              greater than the size of the array, the array must contain a terminating null byte.

       C      (Not in C99 or C11, but in SUSv2, SUSv3, and SUSv4.)  Synonym for lc.  Don't use.

       S      (Not in C99 or C11, but in SUSv2, SUSv3, and SUSv4.)  Synonym for ls.  Don't use.

       p      The void * pointer argument is printed in hexadecimal (as if by %#x or %#lx).

       %      A '%' is written.  No argument is converted.  The complete conversion specification is '%%'.
*/

// %%

// flags: #0-+ et espace

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

/* gerer les flags hh h l ll j z
	hh     A following integer conversion corresponds to a signed char or unsigned char argument, or a following n
              conversion corresponds to a pointer to a signed char argument.

       h      A following integer conversion corresponds to a short or unsigned short argument, or a following n con‐
              version corresponds to a pointer to a short argument.

       l      (ell)  A following integer conversion corresponds to a long or unsigned long argument, or a following n
              conversion corresponds to a pointer to a long argument, or a following c conversion  corresponds  to  a
              wint_t argument, or a following s conversion corresponds to a pointer to wchar_t argument.

       ll     (ell-ell).   A  following integer conversion corresponds to a long long or unsigned long long argument,
              or a following n conversion corresponds to a pointer to a long long argument.

       j      A  following integer conversion corresponds to an intmax_t or uintmax_t argument, or a following n con‐
              version corresponds to a pointer to an intmax_t argument.

       z      A following integer conversion corresponds to a size_t or ssize_t argument, or a following n conversion
              corresponds to a pointer to a size_t argument.
*/

// CF : man 3 printf, man 3 stdarg
//
// Output: write to stdout

symbol_percent_manager()
{
	// The character % is followed by zero or more of the following flags:
	// NB: %%?

	if (*param + 1 == '#')
	/* The value should be converted to an "alternate form".  For o conversions, the first  character  of  the
              output  string  is made zero (by prefixing a 0 if it was not zero already).  For x and X conversions, a
              nonzero result has the string "0x" (or "0X" for X conversions) prepended to it.  For a, A, e, E, f,  F,
              g, and G conversions, the result will always contain a decimal point, even if no digits follow it (nor‐
              mally, a decimal point appears in the results of those conversions only if a digit follows).  For g and
              G  conversions,  trailing  zeros are not removed from the result as they would otherwise be.  For other
              conversions, the result is undefined.
	*/
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
	if (*param + 1 == ' ')
	/* (a  space)  A blank should be left before a positive number (or empty string) produced by a signed con‐
              version.
	*/
	if (*param + 1 == '+')
	/* A sign (+ or -) should always be placed before a number produced by a signed conversion.  By default, a
              sign is used only for negative numbers.  A + overrides a space if both are used.
        */	
}

symbol_manager_hash()
{
	if (*param + 1 == ')
}
