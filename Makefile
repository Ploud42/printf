# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/23 18:57:15 by jsobel            #+#    #+#              #
#    Updated: 2018/10/25 19:50:38 by jsobel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
SRC		=	ft_printf.c \
			ft_intprinter.c \
			ft_check.c \
			ft_strprinter.c
OBJ		=	$(addprefix src/, $(SRC:.c=.o))

CFLAGS = -Wall -Wextra -Werror
CFLAGS += -Iincludes

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all