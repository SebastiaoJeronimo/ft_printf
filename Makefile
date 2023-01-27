# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 18:30:32 by scosta-j          #+#    #+#              #
#    Updated: 2023/01/27 21:47:31 by scosta-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

LIBFT = ./libft/libft.a

AR = ar -rcs

CC	=	gcc

CFLAGS	=	-Wall -Werror -Wextra

RM	=	rm -f

SRC	=	ft_printf.c ft_printf_aux.c

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ) $(LIBFT)
			$(AR) $(NAME) $(OBJ)

$(LIBFT):
	make -C ./libft
	cp ./libft/libft.a $(NAME)
	
clean:
			make clean -C ./libft
			$(RM) $(OBJ) 

fclean:	clean
			make fclean -C ./libft
			$(RM) $(NAME)

re:	fclean $(NAME)