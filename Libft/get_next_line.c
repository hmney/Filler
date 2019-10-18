/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmney <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 21:34:54 by hmney             #+#    #+#             */
/*   Updated: 2019/07/10 15:09:41 by hmney            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		search(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i);
	return (-1);
}

static t_stock	*get_stock(const int fd, t_stock **list)
{
	t_stock *temp;
	t_stock *new;

	temp = *list;
	while (temp != NULL && temp->fd != fd)
		temp = temp->next;
	if (temp != NULL)
		return (temp);
	if (!(new = (t_stock *)malloc(sizeof(t_stock))))
		return (NULL);
	new->fd = fd;
	if (!(new->data = ft_strnew(0)))
	{
		free(new);
		return (NULL);
	}
	new->next = *list;
	*list = new;
	return (new);
}

static void		free_stock(t_stock *stock)
{
	t_stock *temp;

	while (stock != NULL)
	{
		temp = stock;
		stock = stock->next;
		ft_strdel(&(temp->data));
		free(temp);
	}
}

static int		get_line(t_stock *fds, t_stock *stock, char **line, t_gnl env)
{
	if (env.ret < 0)
	{
		free_stock(fds);
		free(env.buf);
		return (-1);
	}
	if (env.ret == 0 && ((stock->data)[0] == '\0'))
	{
		free_stock(fds);
		free(env.buf);
		return (0);
	}
	if (env.index != -1)
	{
		*line = ft_strsub(stock->data, 0, env.index);
		ft_strcpy(stock->data, stock->data + env.index + 1);
	}
	else
	{
		*line = stock->data;
		stock->data = "";
	}
	free(env.buf);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_stock	*fds = NULL;
	t_gnl			env;

	if (fd < 0 || fd > 4096 || line == NULL)
		return (-1);
	if (!(env.stock = get_stock(fd, &fds)))
		return (-1);
	if (!(env.buf = ft_strnew(BUFF_SIZE)))
	{
		free(env.stock);
		return (-1);
	}
	env.ret = 0;
	if ((env.index = search(env.stock->data)) != -1)
		return (get_line(fds, env.stock, line, env));
	while ((env.ret = read(fd, env.buf, BUFF_SIZE)) > 0)
	{
		env.buf[env.ret] = '\0';
		env.temp_free = env.stock->data;
		env.stock->data = ft_strjoin(env.stock->data, env.buf);
		free(env.temp_free);
		if ((env.index = search(env.stock->data)) != -1)
			break ;
	}
	return (get_line(fds, env.stock, line, env));
}
