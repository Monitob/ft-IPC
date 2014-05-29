# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 19:55:21 by jbernabe          #+#    #+#              #
#    Updated: 2014/05/18 22:03:10 by jbernabe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LNAME = ft
NAME = lib$(LNAME).a
CNAME = l$(LNAME)

SRCS =	ft_atoi.c ft_memset.c ft_bzero.c ft_strlen.c \
		ft_memset.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
		ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
		ft_strncat.c ft_memmove.c ft_memcpy.c ft_strcmp.c \
		ft_putchar.c ft_memchr.c ft_memcmp.c ft_memccpy.c \
		ft_putstr.c ft_strlcat.c ft_strchr.c ft_strnequ.c \
		ft_strncmp.c ft_strnstr.c ft_strstr.c ft_putnbr.c \
		ft_strrchr.c ft_memalloc.c ft_memdel.c ft_strnew.c \
		ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
		ft_strmap.c ft_strmapi.c ft_strequ.c ft_strsub.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl.c \
		ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c \
		ft_realloc.c ft_strjoin_glue.c ft_tablen.c ft_deltab.c \
		ft_deltab_int.c ft_close.c ft_fast_strlen.c ft_putendl_fd.c \
		ft_putnbr_fd.c get_next_line.c ft_print_until_char.c ft_is_double.c \
		ft_str_until_char.c ft_tab_free.c  \

V = 0

SILENCE_1 :=
SILENCE_0 :=@
SILENCE = $(SILENCE_$(V))

INCLUDE = ./
CFLAGS = -Wall -Werror -Wextra
CC = $(SILENCE)gcc
LIB = $(SILENCE)ar rc
RM = $(SILENCE)rm -rf

SRCPATH = ./

SRC = $(addprefix $(SRCPATH), $(SRCS))
OBJS= $(SRC:.c=.o)

SKIP_0 := \033[A
SKIP = $(SKIP_$(V))
C = \033[1;34m
U = $(C)[$(NAME)]----->\033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(U)$(C)[COMPILE:\033[1;32m DONE$(C)]\033[0m"
	@echo "$(U)$(C)[BUILD LIB]\033[0;32m"
	$(LIB) $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(SKIP)$(U)$(C)[BUILD  :\033[1;32m DONE$(C)]\033[0m"

%.o: %.c
	@echo "$(U)$(C)[COMPILE: \033[1;31m$<\033[A\033[0m"
	@echo "\033[0;32m"
	$(CC) -o $@ $(CFLAGS) -I $(INCLUDE) -c $<
	@echo "\033[1;31m [.working.]"
	@echo "$(SKIP)\033[A\033[2K$(SKIP)"

clean:
	@echo "$(U)$(C)[CLEAN]\033[0;32m"
	$(RM) $(OBJS)
	@echo "$(SKIP)$(U)$(C)[CLEAN:\033[1;32m   DONE$(C)]\033[0m"

fclean: clean
	@echo "$(U)$(C)[F-CLEAN]\033[1;32m"
	$(RM) $(NAME)
	@echo "$(SKIP)$(U)$(C)[F-CLEAN:\033[1;32m DONE$(C)]\033[0m"

re: fclean all

.PHONY: clean fclean
