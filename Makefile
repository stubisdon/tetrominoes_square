# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juwong <juwong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/29 18:07:57 by dkotov            #+#    #+#              #
#    Updated: 2018/07/06 13:34:38 by juwong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB = libft/libft

HEADER = fillit.h

LIB_SRC = libft/*.c

SRC = *.c

OBJECTS = *.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(LIB).h $(LIB_SRC) $(NAME).h fillit.c valid.c integration.c struct.c board.c solve.c pieces.c tetro_new_string.c
	ar rcs $(NAME).a $(OBJECTS)
	gcc -Wall -Wextra -Werror -o $(NAME) $(NAME).a

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME) $(NAME).a
	rm -f $(LIB).a $(LIB).h.gch $(HEADER).gch

re: fclean all

main:
	gcc -Wall -Wextra -Werror main.c
