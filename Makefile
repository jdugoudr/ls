# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/22 13:52:36 by jdugoudr          #+#    #+#              #
#    Updated: 2019/03/03 19:21:49 by jdugoudr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = #-Wall -Werror -Wextra
RM = rm -rf
NAME = ft_ls
HEADERS = includes 
LIB_DIR = libft/
LIB_FT = libft/libft.a
LIB_HEAD = $(addprefix $(LIB_DIR), $(HEADERS))
SRC_DIR = srcs/
OBJ_DIR = objs/
SRCS = ft_ls.c \
	   error.c \
	   get_data.c \
	   parse.c \
	   ls_utils.c \
	   sort.c \
	   read_dir.c \
	   print_ls.c
#	   scandir.c \
#	   print.c 
OBJS:= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
SRCS:= $(addprefix $(SRC_DIR), $(SRCS))

all: libft $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(LIB_FT)
	@$(CC) -o $@ $(OBJS) $(LIB_FT) -I $(HEADERS) -I $(LIB_HEAD)

libft:
	@make -C $(LIB_DIR) 

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo $<
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADERS) -I $(LIB_HEAD)

$(OBJ_DIR):
	mkdir $@

clean:
	@make clean -C $(LIB_DIR)
	@$(RM) $(OBJS)

fclean: clean
	@make fclean -C $(LIB_DIR)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all libft clean fclean re
