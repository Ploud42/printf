# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/23 18:57:15 by jsobel            #+#    #+#              #
#    Updated: 2018/11/14 19:12:45 by jsobel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =					gcc
NAME =					libftprintf.a
FILES_SRCS =			ft_printf.c			\
						ft_print_int.c		\
						ft_check.c			\
						ft_itoa_intmax.c	\
						ft_print_str.c		\
						ft_print_per.c		\
						ft_convert_o.c		\
						ft_convert_x.c		\
						ft_print_char.c
FOREIGN_FILES_SRCS =	ft_atoi.c			\
						ft_putstr.c			\
						ft_strlen.c			\
						ft_memalloc.c
DIR_FOREIGN_SRCS =		./libft/src
OBJ2 =			$(addprefix obj/, $(SRC:.c=.o))

DIR_OBJS =		./obj
DIR_SRCS =		./src
DIR_INCL =		./includes
DIR_LIBFT =		./libft
FLAGS_COMP =	-Wall -Wextra -Werror
FLAGS_INCL =	-I $(DIR_INCL)
SRCS =			$(FILES_SRCS:%.c=$(DIR_SRCS)/%.c)
OBJ =			$(FILES_SRCS:%.c=$(DIR_OBJS)/%.o)
FOREIGN_SRCS =	$(FOREIGN_FILES_SRCS:%.c=$(DIR_SRCS)/%.c)
FOREIGN_OBJS =	$(FOREIGN_FILES_SRCS:%.c=$(DIR_OBJS)/%.o)

all : $(NAME)

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@mkdir -p $(DIR_OBJS)
	@$(CC) $(FLAGS_COMP) -c $< -o $@ $(FLAGS_INCL)
	@printf "."

$(NAME) : $(OBJ) $(FOREIGN_OBJS)
	@$(MAKE) -C $(DIR_LIBFT)
	@ar rc $(NAME) $(OBJ) $(FOREIGN_OBJS)
	@ranlib $(NAME)

clean :
	@$(MAKE) -C $(DIR_LIBFT) clean
	@rm -f $(OBJ)
	@rm -f $(FOREIGN_OBJS)

fclean : clean
	@$(MAKE) -C $(DIR_LIBFT) fclean
	@rm -f $(NAME)

re : fclean all