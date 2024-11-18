#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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

#endif
