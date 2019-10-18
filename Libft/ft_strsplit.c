/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmney <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 21:09:57 by hmney             #+#    #+#             */
/*   Updated: 2018/10/12 00:31:05 by hmney            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words(const char *str, char c)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	if (str[i] != c)
	{
		counter++;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] != c && str[i - 1] == c)
			counter++;
		i++;
	}
	return (counter);
}

static int	ft_count_char(char *str, char c)
{
	int counter;

	counter = 0;
	while (str[counter] != '\0' && str[counter] != c)
		counter++;
	return (counter);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	*word;
	int		j;
	int		size;

	j = 0;
	if ((tab = (char **)malloc(sizeof(char *) * (words(s, c) + 1))) == NULL)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			size = ft_count_char((char *)s, c);
			word = ft_strnew(size);
			while (*s == c)
				s++;
			word = ft_strsub(s, 0, size);
			tab[j++] = word;
			s = s + size;
		}
		else
			s++;
	}
	tab[j] = 0;
	return (tab);
}
