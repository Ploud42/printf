# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/23 18:57:15 by jsobel            #+#    #+#              #
#    Updated: 2018/10/23 19:59:39 by jsobel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_printf
SRC		=	ft_printf.c \
			ft_intprinter.c \
			ft_check.c \
			ft_strprinter.c
OBJ		=	$(SRC:.c=.o)
LIBR	=	-I./libft/includes/
FlAG	=	-Wall -Wextra -Werror

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			@make -C ./libft
			gcc $(FLAG) $(OBJ) -I./ $(LIBR) -o $(NAME)

$(OBJ)	:	$(SRC)
			gcc $(FLAG) -c $(SRC)

clean	:
			@make -C ./Libft clean
			@rm -f $(OBJ)

fclean	:	clean
			@make -C ./Libft fclean
			@rm -f $(NAME)

re		:	fclean all