/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmney <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 18:28:15 by hmney             #+#    #+#             */
/*   Updated: 2018/10/12 11:40:30 by hmney            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len_s1;
	int		len_s2;

	if (s1 && s2)
	{
		len_s1 = ft_strlen((char *)s1);
		len_s2 = ft_strlen((char *)s2);
		str = ft_strnew(len_s1 + len_s2);
		if (str != NULL)
		{
			ft_strcpy(str, (char *)s1);
			ft_strcat(str, (char *)s2);
			return (str);
		}
	}
	return (NULL);
}
