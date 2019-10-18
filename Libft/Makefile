# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmney <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 14:58:51 by hmney             #+#    #+#              #
#    Updated: 2019/10/05 14:54:18 by hmney            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =  ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isblank.c ft_isdigit.c ft_isgraph.c ft_islower.c ft_isprint.c ft_ispunct.c\
		ft_isspace.c ft_isupper.c ft_itoa.c ft_lstadd.c ft_lstaddback.c ft_lstclear.c ft_lstdel.c ft_lstdelone.c ft_lstfind.c ft_lstiter.c ft_lstlength.c\
		ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c\
		ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c\
		ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c\
		ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c\
		ft_tolower.c ft_toupper.c get_next_line.c ft_length_number.c\

OBJS_DIR = objs

INCLUDES = ../includes/

INCLUDES_FILES = $(addprefix $(INCLUDES),libft.h get_next_line.h)

OBJS =  $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

FLAGS = -Wextra -Werror -Wall

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJS): $(OBJS_DIR)/%.o : %.c $(INCLUDES_FILES) | $(OBJS_DIR)
	@gcc -o $@ -c $< $(FLAGS) -I $(INCLUDES)

clean:
	@/bin/rm -rf $(OBJS_DIR)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)
