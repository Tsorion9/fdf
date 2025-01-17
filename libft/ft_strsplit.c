/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphobos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:20:18 by mphobos           #+#    #+#             */
/*   Updated: 2019/10/04 13:57:55 by mphobos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size_strsplit(const char *s, int c)
{
	int		size;
	int		i;

	size = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != (char)c)
		{
			size++;
			while (s[i] != '\0' && s[i] != (char)c)
				i++;
			if (s[i] == '\0')
				return (size);
		}
		i++;
	}
	return (size);
}

static char		**ft_mas_strsplit(const char *s, int c, int index, int size)
{
	char	**res;
	int		i;

	if (!(res = (char**)ft_memalloc(8 * (ft_size_strsplit(s, c) + 1))))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != (char)c)
		{
			size = 0;
			while (s[i] != '\0' && s[i] != (char)c)
			{
				i++;
				size++;
			}
			if (!(res[index] = (char*)ft_memalloc(sizeof(char) * (size + 1))))
				return (0);
			if (s[i] == '\0')
				return (res);
			index++;
		}
		i++;
	}
	return (res);
}

static char		**ft_sup(const char *s, char **res, int c, int i)
{
	int		j;
	int		index;

	index = 0;
	while (s[i] != '\0')
	{
		if (s[i] != (char)c)
		{
			j = 0;
			while (s[i] != '\0' && s[i] != (char)c)
			{
				res[index][j] = s[i];
				i++;
				j++;
			}
			res[index][j] = '\0';
			if (s[i] == '\0')
				return (res);
			index++;
		}
		i++;
	}
	return (res);
}

char			**ft_strsplit(const char *s, int c)
{
	char	**res;
	int		i;
	int		index;

	if (!s)
		return (NULL);
	if (!(res = ft_mas_strsplit(s, c, 0, 0)))
		return (0);
	i = 0;
	index = 0;
	return (ft_sup(s, res, c, i));
}
