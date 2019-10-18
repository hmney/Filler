/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_data2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmney <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 11:30:58 by hmney             #+#    #+#             */
/*   Updated: 2019/07/23 18:37:17 by hmney            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_turn(t_filler *store)
{
	char *line;

	if (get_next_line(0, &line) == 1)
	{
		if (ft_strstr(line, "p1") != NULL)
		{
			store->my_turn = -1;
			store->enemy_turn = -2;
		}
		else
		{
			store->my_turn = -2;
			store->enemy_turn = -1;
		}
		ft_strdel(&line);
	}
}

int		get_shape_position(t_filler *store)
{
	int index_1;

	if (!(store->shape.positions = (t_coords *)malloc(sizeof(t_coords) *
					store->shape.number)))
		return (0);
	index_1 = -1;
	store->tmp1 = 0;
	while (++index_1 < store->token_lines)
	{
		store->index = -1;
		while (++store->index < store->token_colonnes)
			if (store->token[index_1][store->index] == '*')
			{
				store->shape.positions[store->tmp1].x = index_1;
				store->shape.positions[store->tmp1++].y = store->index;
			}
	}
	store->shape.shift.x = store->shape.positions[0].x;
	store->shape.shift.y = store->shape.positions[0].y;
	while (--store->tmp1 >= 0)
	{
		store->shape.positions[store->tmp1].x -= store->shape.shift.x;
		store->shape.positions[store->tmp1].y -= store->shape.shift.y;
	}
	return (1);
}

void	free_store(t_filler *store)
{
	int index;

	index = -1;
	if (store->board)
		while (store->board[++index])
			ft_strdel(&store->board[index]);
	free(store->board);
	index = -1;
	if (store->token)
		while (store->token[++index])
			ft_strdel(&store->token[index]);
	free(store->token);
	free(store->shape.positions);
}
