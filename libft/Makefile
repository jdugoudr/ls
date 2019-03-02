# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 13:20:41 by jdugoudr          #+#    #+#              #
#    Updated: 2019/03/01 16:05:05 by jdugoudr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
AR = ar rcs
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
HEADERS = includes 
HEADERS_PRINTF = includes/includes_printf/
LIBS =
SRC_DIR = srcs/
SRC_DIR_PRINTF = srcs/srcs_printf/
OBJ_DIR = objs/
################################################################################
#####								print				 				   #####
SRCS = ft_putchar.c ft_putchar_fd.c ft_putstr.c ft_putnstr.c ft_putstr_fd.c \
	ft_putnstr_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c
#####								print utility						   #####
SRCS += ft_isalnum.c ft_isprint.c ft_toupper.c ft_tolower.c 
#####								number								   #####
SRCS += ft_atoi.c ft_atoi_base.c ft_atoui_base.c ft_atoul_base.c ft_isdigit.c \
	ft_nblen.c ft_swap.c 
#####								maths str							   #####
SRCS += ft_addstr.c ft_faddstr.c ft_subtrackstr.c ft_multistr.c \
	ft_fmultistr.c ft_divstr.c ft_fdivstr.c ft_expstr.c ft_powerstr.c \
	ft_fmultistr_utility.c
#####								str basic							   #####
SRCS += ft_isascii.c ft_isalpha.c ft_strtoupper.c ft_strlen.c ft_strcmp.c \
	ft_acmpi.c ft_strncmp.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c \
	ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strdup.c \
	ft_strndup.c ft_strjoin.c ft_strjoinfree.c ft_strsub.c	ft_strtrim.c 
#####								str utility							   #####
SRCS += ft_strnew.c ft_strdel.c ft_tabstrdel.c ft_strclr.c ft_striter.c \
	ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
	ft_strsplit.c ft_tablen.c ft_swapstr.c ft_strfill.c ft_tabsort.c \
	ft_strrev.c
#####								to str								   #####
SRCS += ft_itoa.c ft_stoa.c ft_ctoa.c ft_ltoa.c ft_lltoa.c ft_dbtoa.c \
	ft_ldbtoa.c ft_imaxtoa.c ft_zttoa.c ft_szttoa.c \
	ft_uitoa.c ft_uctoa.c ft_ustoa.c ft_ultoa.c ft_ulltoa.c ft_uimaxtoa.c \
	ft_itoa_base.c ft_stoa_base.c ft_ltoa_base.c ft_zttoa_base.c \
	ft_uitoa_base.c ft_uctoa_base.c ft_ustoa_base.c ft_ultoa_base.c \
	ft_ulltoa_base.c ft_uimaxtoa_base.c ft_itoa_hex.c ft_ltoa_hex.c \
	ft_zttoa_hex.c ft_uitoa_hex.c ft_ultoa_hex.c ft_ulltoa_hex.c \
	ft_uimaxtoa_hex.c ft_zttoa_oct.c ft_uitoa_oct.c ft_uctoa_oct.c \
	ft_ustoa_oct.c ft_ultoa_oct.c ft_ulltoa_oct.c ft_uimaxtoa_oct.c \
	ft_lsttostr.c ft_lstjoinstr.c ft_tabtostr.c 
#####								list								   #####
SRCS += ft_lstnew.c ft_lstdel.c ft_lstadd.c ft_lstdelone.c ft_lstappend.c \
	ft_lstdelstr.c ft_lstremove.c ft_lstnewstr.c
#####								list utility						   #####
SRCS += ft_lstprint.c ft_splittolst.c ft_lstlen.c ft_strtolst.c ft_lstiter.c \
	ft_lstmap.c 
#####								memory								   #####
SRCS += ft_memalloc.c ft_memdel.c ft_memset.c ft_bzero.c ft_memmove.c \
	ft_memcpy.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memprint.c
#####								utility								   #####
SRCS += ft_ftoa_utility.c ft_faddstr_utility.c  get_next_line.c \
		ft_tabstr_realloc.c
################################################################################
#####								printf								   #####
SRCS_PRINTF += ft_printf.c ft_fprintf.c convert_dcs.c convert_c.c convert_dd.c \
			   convert_prc.c convert_p.c convert_x.c convert_u.c convert_o.c \
			   convert_f.c convert_utility.c error.c init_convert.c \
			   init_flags.c flag_blank.c flag_less.c flag_minisize.c \
			   flag_more.c flag_point.c flag_point_utility.c flag_zero.c \
			   flag_l.c flag_ll.c flag_lll.c flag_hh.c flag_h.c flag_diese.c \
			   flag_z.c flag_j.c flag_star.c flag_utility.c
################################################################################
OBJS:= $(addprefix $(OBJ_DIR),$(SRCS:.c=.o))
OBJS_PRINTF:= $(addprefix $(OBJ_DIR), $(SRCS_PRINTF:.c=.o))
SRCS:= $(addprefix $(SRC_DIR), $(SRCS))
SRCS_PRINTF:= $(addprefix $(SRC_DIR_PRINTF), $(SRCS_PRINTF))
RM= rm -rf

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(OBJS_PRINTF)
	@$(AR) $@ $(OBJS) $(OBJS_PRINTF)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo $<
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADERS)

$(OBJ_DIR)%.o: $(SRC_DIR_PRINTF)%.c
	@echo $<
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADERS_PRINTF)

$(OBJ_DIR):
	mkdir $@

clean:
	@$(RM) $(OBJS) $(OBJS_PRINTF)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
