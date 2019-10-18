/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmney <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 10:39:06 by hmney             #+#    #+#             */
/*   Updated: 2019/07/23 18:31:36 by hmney            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# define ABS(value) (value < 0 ? -value : value)

typedef struct	s_coords
{
	int			x;
	int			y;
}				t_coords;

typedef struct	s_token
{
	int			number;
	t_coords	shift;
	t_coords	*positions;
}				t_token;

typedef struct	s_filler
{
	char		**board;
	char		**token;
	t_token		shape;
	int			board_lines;
	int			board_colonnes;
	int			token_lines;
	int			token_colonnes;
	t_coords	place_it;
	t_coords	me;
	t_coords	enemy;
	char		my_turn;
	char		enemy_turn;
	int			min;
	int			result;
	int			tmp1;
	int			tmp2;
	int			index;
}				t_filler;

void			get_turn(t_filler *store);
int				get_size_board(t_filler *store);
int				get_board(t_filler *store, int index);
void			get_size_token(t_filler *store, char *line);
int				get_token(t_filler *store, int index);
int				store_data(t_filler *store);
int				get_shape_position(t_filler *store);
void			free_store(t_filler *store);
void			flood_fill(t_filler *store);
int				check_place(t_filler *store, int index_1, int index_2);
void			filler(t_filler *store);

#endif
