/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:25:21 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/19 12:22:19 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int			ft_printf(const char *fmt, ...);

/* Functions for managing conversion specificators */
const char	*ft_spec_conv(const char *fmt, va_list args, size_t *b_writ);
void		conv_num(const char *fmt, va_list args, char *flg, size_t *b_writ);
void		conv_hex(const char *fmt, va_list args, char *flg, size_t *b_writ);
void		conv_txt(const char *fmt, va_list args, size_t *b_writ);

/* Functions for conversion to hexadecimal */
char		*ft_itohex(char *dest, unsigned long nb, char style);
void		hex_set_case(char style, int *case_var);
char		*hex_handle_zero(char *hex_value, char style);
char		*hex_format_string(int i, char *hex_value, char style);

/* Functions for output and counting written bytes */
size_t		ft_putchar_fd_count(char c, int fd);
size_t		ft_putstr_fd_count(char *s, int fd);
size_t		ft_putnbr_fd_count(int n, int fd);
size_t		ft_put_ui_fd_count(unsigned int n, int fd);

#endif
