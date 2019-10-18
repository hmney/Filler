/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmney <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 11:16:49 by hmney             #+#    #+#             */
/*   Updated: 2019/07/18 11:17:28 by hmney            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	flood_fill2(t_filler *store, int index_2, int index_3, int target)
{
	int value;

	value = (target == -1 || target == -2) ? 1 : target + 1;
	if (index_2 - 1 >= 0 && index_3 - 1 >= 0
			&& store->board[index_2 - 1][index_3 - 1] == 0)
		store->board[index_2 - 1][index_3 - 1] += value;
	if (index_2 - 1 >= 0 && store->board[index_2 - 1][index_3] == 0)
		store->board[index_2 - 1][index_3] += value;
	if (index_2 - 1 >= 0 && index_3 + 1 <= store->board_colonnes
			&& store->board[index_2 - 1][index_3 + 1] == 0)
		store->board[index_2 - 1][index_3 + 1] += value;
	if (index_3 - 1 >= 0 && store->board[index_2][index_3 - 1] == 0)
		store->board[index_2][index_3 - 1] += value;
	if (index_3 + 2 < store->board_colonnes
			&& store->board[index_2][index_3 + 1] == 0)
		store->board[index_2][index_3 + 1] += value;
	if (index_2 + 1 < store->board_lines && index_3 - 1 >= 0
			&& store->board[index_2 + 1][index_3 - 1] == 0)
		store->board[index_2 + 1][index_3 - 1] += value;
	if (index_2 + 1 < store->board_lines
			&& store->board[index_2 + 1][index_3] == 0)
		store->board[index_2 + 1][index_3] += value;
	if (index_2 + 1 < store->board_lines && index_3 + 1 < store->board_colonnes
			&& store->board[index_2 + 1][index_3 + 1] == 0)
		store->board[index_2 + 1][index_3 + 1] += value;
}

void		flood_fill(t_filler *store)
{
	int		index_1;
	int		index_2;
	int		index_3;
	char	target;

	index_1 = -1;
	target = store->enemy_turn;
	while (++index_1 < store->board_colonnes)
	{
		index_2 = -1;
		while (++index_2 < store->board_lines)
		{
			index_3 = -1;
			while (++index_3 < store->board_colonnes)
			{
				if (store->board[index_2][index_3] == target)
					flood_fill2(store, index_2, index_3, target);
			}
		}
		if (target == -1 || target == -2)
			target = 1;
		else
			target++;
	}
}
