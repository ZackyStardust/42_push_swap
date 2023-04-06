# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 15:53:37 by fpereira          #+#    #+#              #
#    Updated: 2023/03/15 15:53:40 by fpereira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a
SRC =	$(wildcard *.c)

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -g -I../../includes

all:$(NAME)

$(NAME): $(SRC:.c=.o)
			ar rc $(NAME) $(SRC:.c=.o)
clean:
	$(RM)	$(SRC:.c=.o)
fclean: clean
		$(RM)	$(NAME)
re:	fclean	$(NAME)

.PHONY: all clean fclean re