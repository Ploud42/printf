# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/03 16:51:36 by hben-yah          #+#    #+#              #
#    Updated: 2018/06/10 17:11:06 by juliensobel      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
SRCS	=	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
			ft_isdigit.c ft_islower.c ft_isprint.c ft_isupper.c ft_itoa.c \
			ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
			ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
			ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c \
			ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
			ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c \
			ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
			ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
			ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
			ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
			ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c \
			ft_toupper.c ft_isspace.c ft_strtoupper.c ft_strtolower.c \
			ft_charswap.c ft_strrev.c ft_isspace_wnt.c ft_strlcpy.c \
			ft_indexof.c ft_atoi_base.c ft_itoa_base.c ft_putnbr_base.c \
			ft_convert_base.c ft_hasnodupl.c ft_nbrlen.c ft_isprime.c \
			ft_pow.c ft_sqrt.c ft_putstrtab.c ft_sortinttab.c ft_putnbrtab.c \
			ft_intswap.c
OBJS	=	$(SRCS:.c=.o)
INCL	=	./includes
FLAG	=	-Wall -Wextra -Werror

all		:	$(NAME)

$(NAME)	:	$(SRCS) includes/libft.h
			gcc $(FLAG) -I $(INCL) -c $(SRCS)
			@ar rc $(NAME) $(OBJS)
			@ranlib $(NAME)

clean	:
			@rm -f $(OBJS)

fclean	:	clean
			@rm -f $(NAME)

re		:	fclean all
