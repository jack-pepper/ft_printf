# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 09:35:38 by mmalie            #+#    #+#              #
#    Updated: 2024/12/03 09:01:23 by mmalie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### Name of the file obtained after compilation
NAME = libftprintf.a

### Compilation settings
CC=cc
CFLAGS=-Wall -Wextra -Werror -I ./libft
AR=ar
ARFLAGS=-rcs

### Dependencies
DEPS_SRC = ft_printf.h \
DEPS_BONUS = ft_printf_bonus.h \

LIBFT_PATH = ./libft
LIBFT = ./libft/libft.a

### Source files
SRC = ft_printf.c ft_spec_conv.c ft_itohex.c ft_put_ui_fd_count.c \
      ft_putchar_fd_count.c ft_putstr_fd_count.c ft_putnbr_fd_count.c \

BONUS_SRC = ft_printf_bonus.c ft_spec_conv_bonus.c ft_itohex_bonus.c \
	ft_put_ui_fd_count_bonus.c ft_putchar_fd_count_bonus.c \
	ft_putstr_fd_count_bonus.c ft_putnbr_fd_count_bonus.c \

### Object files
OBJ = $(SRC:.c=.o)
ALL_SRC = ${SRC} ${BONUS_SRC}
ALL_OBJ = $(ALL_SRC:.c=.o)

### Default rule (compile the executable)
all: $(NAME)

### Compile .c files into .o files
# $< = current source file ; $@ = matching object file
# The -c flag asks the compiler not to link the files
# and to produce only the object file.
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

### Main rule
$(NAME): $(OBJ)
	cd libft && make
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

# Make bonus rule
bonus: $(ALL_OBJ)
	cd libft && make
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(ALL_OBJ)

# Rule to clean (remove) the object files
clean:
	cd libft && make clean
	rm -f $(OBJ) $(ALL_OBJ)

# Rule to clean (remove) the object files and the executable
fclean: clean
	cd libft && make fclean
	rm -f $(NAME)

# Rule to recompile everything (execute fclean, then re)
re: fclean all

# Shows that those targets are not files but commands
.PHONY: all clean fclean re bonus libft
