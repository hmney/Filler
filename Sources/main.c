/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmney <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 23:28:02 by hmney             #+#    #+#             */
/*   Updated: 2019/07/23 15:11:42 by hmney            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_filler	store;
	int			turn;
	int			err;

	turn = 0;
	while (1)
	{
		if (turn == 0)
			get_turn(&store);
		if ((err = store_data(&store)) == 1)
		{
			flood_fill(&store);
			filler(&store);
			free_store(&store);
			turn++;
		}
		else if (err == 0)
		{
			free_store(&store);
			return (1);
		}
		else
			return (1);
	}
	return (0);
}
