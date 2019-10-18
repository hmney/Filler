# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmney <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 14:53:27 by hmney             #+#    #+#              #
#    Updated: 2019/09/30 18:18:36 by hmney            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hmney.filler

LIB = Libft/libft.a

SRCS = Sources/main.c Sources/store_data.c Sources/flood_fill.c Sources/filler.c Sources/store_data2.c

FLAGS = -Wall -Werror -Wextra

INCLUDES = includes/

INCLUDES_FILES = $(addprefix $(INCLUDES)/,libft.h get_next_line.h filler.h)

all: libft_ $(NAME)

libft_:
	@make -C Libft

$(NAME): $(SRCS) $(INCLUDES_FILES) $(LIB)
	@gcc $(FLAGS) $(SRCS) -o $(NAME) $(LIB) -I $(INCLUDES)

clean:
	@make clean -C Libft
	@/bin/rm -f $(OBJS)

fclean: clean
	@make fclean -C Libft
	@/bin/rm -f $(NAME)

re: fclean all
