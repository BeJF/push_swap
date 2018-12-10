# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/14 12:17:51 by jfinet            #+#    #+#              #
#    Updated: 2018/12/07 08:49:52 by jfinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = new_tab.c operations.c operations2.c push_swap.c algo5data.c tools.c sort_a.c first_sort.c sort_b.c algo3.c algo2.c error_checker.c make_piles.c ft_atoi.c ft_strlen.c get_minmax.c print_piles.c tools2.c sort_smallparts_a.c median.c

BIN = new_tab.o operations.o operations2.o push_swap.o algo5data.o tools.o sort_a.o first_sort.o sort_b.o algo3.o algo2.o error_checker.o make_piles.o ft_atoi.o ft_strlen.o get_minmax.o print_piles.o tools2.o sort_smallparts_a.o median.o

all : $(NAME)

$(NAME) :
	@gcc -c -O3 $(SRC)
	@gcc -o $(NAME) -I. $(BIN)

clean :
	@/bin/rm -f *.o

fclean : clean
	@/bin/rm -f $(NAME)

re : fclean all
