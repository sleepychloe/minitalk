# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 13:59:42 by yhwang            #+#    #+#              #
#    Updated: 2022/06/25 23:42:25 by yhwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME = server
CLIENT_NAME = client

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT_DIR = ./libft
LIBFT_NAME = libft.a
LIBFT = $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))

SERVER_FILES = server \
	       	utils

CLIENT_FILES = client \
		utils

INCS_DIR = ./incs

SRCS_DIR = ./srcs

SERVER_SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(SERVER_FILES)))
SERVER_OBJS = $(addprefix $(SRCS_DIR)/, $(addsuffix .o, $(SERVER_FILES)))

CLIENT_SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(CLIENT_FILES)))
CLIENT_OBJS = $(addprefix $(SRCS_DIR)/, $(addsuffix .o, $(CLIENT_FILES)))

.c.o: $(SERVER_SRCS) $(CLIENT_SRCS) $(INCS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCS_DIR)

all: $(LIBFT_NAME) $(SERVER_NAME) $(CLIENT_NAME)

$(LIBFT_NAME):
	make -C $(LIBFT_DIR)

$(SERVER_NAME): $(SERVER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT_NAME): $(CLIENT_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(SERVER_OBJS)
	$(RM) $(CLIENT_OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(SERVER_NAME)
	$(RM) $(CLIENT_NAME)

re: fclean all

.PHONY: all clean fclean re
