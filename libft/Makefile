# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 08:59:34 by mmalie            #+#    #+#              #
#    Updated: 2024/12/03 09:00:31 by mmalie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


### Name of the file obtained after compilation
NAME = libft.a

### Compilation settings
CC=cc
CFLAGS=-Wall -Wextra -Werror
AR=ar
ARFLAGS=-rcs

### Dependencies
DEPS = libft.h

### Source files
LIBC = ft_strlen.c ft_memset.c ft_strlcpy.c ft_strdup.c ft_strrev.c \

EXTRA = ft_itoa.c \

SRC = ${LIBC} ${EXTRA}

### Object files
OBJ = $(SRC:.c=.o)

### Default rules (compile the executable)
all: $(NAME)

### Compile .c files into .o files
# $< = current source file ; $@ = matching object file
# The -c flag asks the compiler not to link the files
# and to produce only the object file.
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

### Create a static library
$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

# Rule to clean (remove) the object files
clean:
	rm -f $(OBJ)

# Rule to clean (remove) the object files and the executable
fclean: clean
	rm -f $(NAME)

# Rule to recompile everything (execute fclean, then re)
re: fclean all

# Shows that those targets are not files but commands
.PHONY: all clean fclean re
