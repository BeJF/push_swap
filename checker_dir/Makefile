# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/14 12:17:51 by jfinet            #+#    #+#              #
#    Updated: 2018/12/19 13:40:30 by jfinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

SRC = call_instructions.c checker.c error_checker.c make_piles.c new_tab.c operations.c operations2.c print.c get_next_line.c

BIN = call_instructions.o checker.o error_checker.o make_piles.o new_tab.o operations.o operations2.o print.o get_next_line.o

all : $(NAME)

$(NAME) :
	@make -C ./libft/
	@cp ./libft/libft.a ./
	@gcc -c -O3 $(SRC)
	@gcc -o $(NAME) -I. $(BIN) libft.a

clean :
	@/bin/rm -f *.o
	@make clean -C ./libft/

fclean : clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f libft.a
	@make fclean -C ./libft/

re : fclean all
