# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 18:35:35 by fpereira          #+#    #+#              #
#    Updated: 2023/03/15 16:50:42 by fpereira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
RM			=	rm -f
MKD			=	mkdir
INC			=	-I ./includes

NAME		=	push_swap

OBJ_PATH	=	./obj
SRCS		=	$(wildcard $(SRC_PATH)/*.c)
OBJ_SRCS	= 	$(patsubst $(SRC_PATH)/%.c,$(OBJ_PATH)/%.o,$(SRCS))

SRC_LIBFT	=	./srcs/libft
LIBFT		=	./srcs/libft/libft.a

SRC_PRINTF	=	./srcs/printf
FT_PRINTF	=	./srcs/printf/ft_printf.a

SRC_PATH	=	./srcs

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(LIBFT): $(SRC_LIBFT)/Makefile
	make -C $(SRC_LIBFT)

$(FT_PRINTF): $(SRC_PRINTF)/Makefile
	make -C $(SRC_PRINTF)

$(NAME) : $(OBJ_SRCS)
	$(CC) $(CFLAGS) $(OBJ_SRCS) $(INC) $(LIBFT) $(FT_PRINTF) -o $(NAME)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) $(OBJ_PATH)/*.o
	make fclean -C $(SRC_LIBFT)
	make fclean -C $(SRC_PRINTF)

fclean: clean
		make fclean -C $(SRC_LIBFT)
		make fclean -C $(SRC_PRINTF)
		$(RM) $(NAME)
		$(RM) $(CLIENT)
		$(RM) $(SERVER)
		if [ -d $(OBJ_PATH) ]; then rmdir $(OBJ_PATH); fi

re: fclean all