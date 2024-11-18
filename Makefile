# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmalie <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 09:35:38 by mmalie            #+#    #+#              #
#    Updated: 2024/11/14 09:35:45 by mmalie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### Name of the file obtained after compilation
NAME = libftprintf.a

### Compilation settings
CC=cc
CFLAGS=-Wall -Wextra -Werror
AR=ar
ARFLAGS=-rcs

### Dependencies
DEPS = ft_printf.h \

### Source files
LIBFTPRINTF = ft_printf.c \

##BONUS_SRC =

MANDATORY_SRC = ${LIBFTPRINTF}
##ALL_SRC = ${MANDATORY_SRC} ${BONUS_SRC}

### Object files
MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)
##ALL_OBJ = $(ALL_SRC:.c=.o)

### Default rules (compile the executable)
all: $(NAME)

### Compile .c files into .o files
# $< = current source file ; $@ = matching object file
# The -c flag asks the compiler not to link the files
# and to produce only the object file.
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

### Create a static library
$(NAME): $(MANDATORY_OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(MANDATORY_OBJ)

# Make bonus rule
##bonus: $(ALL_OBJ)
##	$(AR) $(ARFLAGS) $(NAME) $(ALL_OBJ)

# Rule to clean (remove) the object files
clean:
	rm -f $(MANDATORY_OBJ)
##rm -f $(ALL_OBJ)


# Rule to clean (remove) the object files and the executable
fclean: clean
	rm -f $(NAME)

# Rule to recompile everything (execute fclean, then re)
re: fclean all

# Shows that those targets are not files but commands
.PHONY: all clean fclean re
