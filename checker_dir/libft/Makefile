# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/17 12:48:04 by jfinet            #+#    #+#              #
#    Updated: 2018/10/03 22:29:13 by jfinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = *.c

BIN = *.o

all : $(NAME)

$(NAME) :
	@gcc -Wall -Wextra -Werror -I. -c $(SRC)
	@ar rc $(NAME) $(BIN)
	@ranlib $(NAME)

clean : 
	@/bin/rm -f *.o

fclean : clean
	@/bin/rm -f $(NAME)

re : fclean all
