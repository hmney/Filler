/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmney <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 10:42:53 by hmney             #+#    #+#             */
/*   Updated: 2019/07/18 13:17:27 by hmney            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_place(t_filler *store, int index_1, int index_2)
{
	int index;
	int intersection;

	index = -1;
	intersection = 0;
	store->result = 0;
	while (++index < store->shape.number)
	{
		store->tmp1 = index_1 + store->shape.positions[index].x;
		store->tmp2 = index_2 + store->shape.positions[index].y;
		if (store->tmp1 < 0 || store->tmp1 >= store->board_lines)
			return (-1);
		if (store->tmp2 < 0 || store->tmp2 >= store->board_colonnes)
			return (-1);
		if (store->board[store->tmp1][store->tmp2] == store->enemy_turn)
			return (-1);
		if (store->board[store->tmp1][store->tmp2] == store->my_turn)
			intersection++;
		if (intersection > 1)
			return (-1);
		if (store->board[store->tmp1][store->tmp2] != store->my_turn)
			store->result += store->board[store->tmp1][store->tmp2];
	}
	return ((intersection == 0) ? -1 : store->result);
}

void	print_coords(t_filler *store)
{
	ft_putnbr(store->place_it.x);
	ft_putchar(' ');
	ft_putnbr(store->place_it.y);
	ft_putchar('\n');
}

void	store_coords(t_filler *store, int index_1, int index_2)
{
	store->place_it.x = index_1 - store->shape.shift.x;
	store->place_it.y = index_2 - store->shape.shift.y;
}

int		place_it(t_filler *store, int result, int index_1, int index_2)
{
	if (result < store->min)
	{
		store->min = result;
		store_coords(store, index_1, index_2);
	}
	else if (result == 0)
	{
		store_coords(store, index_1, index_2);
		return (1);
	}
	return (0);
}

void	filler(t_filler *store)
{
	int index_1;
	int index_2;
	int can_break;

	index_1 = -1;
	store->min = 100000;
	store->place_it.x = -1;
	store->place_it.y = -1;
	can_break = 0;
	while (++index_1 < store->board_lines)
	{
		index_2 = -1;
		while (++index_2 < store->board_colonnes)
		{
			if ((store->result = check_place(store, index_1, index_2)) != -1)
			{
				can_break = place_it(store, store->result, index_1, index_2);
				if (can_break == 1)
					break ;
			}
		}
		if (can_break == 1)
			break ;
	}
	print_coords(store);
}
