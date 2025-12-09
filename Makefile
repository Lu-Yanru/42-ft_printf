# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yanlu <yanlu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/24 11:49:58 by yanlu             #+#    #+#              #
#    Updated: 2025/12/09 13:52:02 by yanlu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

# Source files, obj files and header files
SRC = ft_printf.c ft_putchar_fd_l.c ft_putstr_fd_l.c ft_putnbr_fd_l.c ft_puthex.c \
	ft_putunbr.c ft_putptr.c ft_strlcpy.c ft_strlen.c

OBJ = $(SRC:.c=.o)

IDIR = .

HEADER = ft_printf.h

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I$(IDIR) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
