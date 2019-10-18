/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmney <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 00:08:40 by hmney             #+#    #+#             */
/*   Updated: 2019/07/23 18:34:34 by hmney            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_size_board(t_filler *store)
{
	char	*line;
	int		index;

	if (get_next_line(0, &line) == 1)
	{
		index = 8;
		store->board_lines = ft_atoi(line + index);
		index += ft_length_number(store->board_lines);
		store->board_colonnes = ft_atoi(line + index);
		ft_strdel(&line);
	}
	else
		return (0);
	return (1);
}

int		get_board(t_filler *store, int index)
{
	char	*line;
	int		length;
	int		position;

	if (get_next_line(0, &line) == 1)
	{
		position = ft_length_number(store->board_lines);
		position += (position < 3);
		length = ft_strlen(line);
		if (!(store->board[index] = ft_strnew(length - position - 1)))
			return (0);
		store->index = 0;
		while (position++ < length)
		{
			if (line[position] == 'O')
				store->board[index][store->index] = -1;
			else if (line[position] == 'X')
				store->board[index][store->index] = -2;
			else
				store->board[index][store->index] = 0;
			store->index++;
		}
		ft_strdel(&line);
	}
	return (1);
}

void	get_size_token(t_filler *store, char *line)
{
	int index;

	index = 6;
	store->token_lines = ft_atoi(line + index);
	index += ft_length_number(store->token_lines);
	store->token_colonnes = ft_atoi(line + index);
	ft_strdel(&line);
}

int		get_token(t_filler *store, int index)
{
	char	*line;
	int		index_2;

	if (get_next_line(0, &line) == 1)
	{
		if (index == 0)
		{
			store->shape.number = 0;
			store->tmp1 = store->token_lines + 1;
			if (!(store->token = (char **)malloc(sizeof(char *) * store->tmp1)))
				return (0);
			store->token[store->token_lines] = NULL;
		}
		store->token[index] = ft_strnew(store->token_colonnes);
		index_2 = -1;
		while (++index_2 < store->token_colonnes)
		{
			store->token[index][index_2] = line[index_2];
			if (line[index_2] == '*')
				store->shape.number++;
		}
		ft_strdel(&line);
	}
	return (1);
}

int		store_data(t_filler *store)
{
	char	*line;
	int		index;

	if (!get_size_board(store))
		return (-1);
	if (get_next_line(0, &line) == 1)
		ft_strdel(&line);
	index = -1;
	store->tmp1 = store->board_lines + 1;
	if (!(store->board = (char **)malloc(sizeof(char *) * store->tmp1)))
		return (0);
	store->board[store->board_lines] = NULL;
	while (++index < store->board_lines)
		if (!get_board(store, index))
			return (0);
	if (get_next_line(0, &line) == 1)
		get_size_token(store, line);
	index = -1;
	while (++index < store->token_lines)
		if (!get_token(store, index))
			return (0);
	if (!get_shape_position(store))
		return (0);
	return (1);
}
