# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/22 19:54:32 by nsierra-          #+#    #+#              #
#    Updated: 2015/04/16 06:57:17 by cfernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libfttree.a

SRC =		tree_new.c \
			tree_insert.c \
			tree_get.c \
			tree_successor.c \
			tree_predecessor.c \
			tree_destroy.c \
			tree_delete_node.c \
			tree_get_iter.c \
			tree_print.c \
			tree_delete_fixup.c \
			left_rotate.c \
			right_rotate.c \
			fttree_iter.c \
			misc.c


OBJ = 		$(SRC:.c=.o)

CC = 		gcc

CFLAGS = 	-pedantic -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -I. -c $(SRC)
	ar rc  $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

test: all
	gcc -L./ -lfttree main.c -o test
	./test

re: fclean all
