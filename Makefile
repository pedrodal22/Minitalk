# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfranco- <pfranco-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 19:06:41 by pedro             #+#    #+#              #
#    Updated: 2024/09/03 23:19:26 by pfranco-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client 
FLAGS = -Wall -Wextra -Werror

SRC_SERVER = server.c ft_printf.c
SRC_CLIENT = client.c ft_printf.c
SRC = $(SRC_SERVER) $(SRC_CLIENT)

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJS = $(OBJ_SERVER) $(OBJ_CLIENT)

GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m

.PHONY: all clean fclean re

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_SERVER)
	cc $(FLAGS) $(OBJ_SERVER) -o $(SERVER)

$(CLIENT): $(OBJ_CLIENT)
	cc $(FLAGS) $(OBJ_CLIENT) -o $(CLIENT)
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all
