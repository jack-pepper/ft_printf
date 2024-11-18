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
NAME = libft.a

### Compilation settings
CC=cc
CFLAGS=-Wall -Wextra -Werror
AR=ar
ARFLAGS=-rcs

### Dependencies
DEPS = libft.h

### Source files
LIBC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_toupper.c ft_tolower.c ft_atoi.c ft_strlen.c ft_memset.c ft_bzero.c \
ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_strdup.c ft_calloc.c \
ft_strrev.c

EXTRA = ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_split.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_substr.c ft_striteri.c

BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstmap.c ft_lstiter.c

MANDATORY_SRC = ${LIBC} ${EXTRA}
ALL_SRC = ${MANDATORY_SRC} ${BONUS_SRC}

### Object files
MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)
ALL_OBJ = $(ALL_SRC:.c=.o)

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
bonus: $(ALL_OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(ALL_OBJ)

# Rule to clean (remove) the object files
clean:
	rm -f $(ALL_OBJ)

# Rule to clean (remove) the object files and the executable
fclean: clean
	rm -f $(NAME)

# Rule to recompile everything (execute fclean, then re)
re: fclean all

# Shows that those targets are not files but commands
.PHONY: all clean fclean re bonus
