/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-abovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:44:01 by md-abovi          #+#    #+#             */
/*   Updated: 2019/11/14 19:44:06 by md-abovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void		*freeall(char **ptr, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
		free(ptr[i++]);
	return (NULL);
}

static size_t	count_words(char const *str, char c)
{
	size_t		i;
	size_t		words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c)
		{
			while (str[i] != c && str[i])
				i++;
			words++;
		}
	}
	return (words);
}

static size_t	get_size(char const *str, char c, size_t index)
{
	size_t		size;

	size = 0;
	while (str[index] != c && str[index++])
		size++;
	return (size);
}

char			**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		k;
	char		**ret;

	i = 0;
	k = 0;
	if ((!s) || !(ret = malloc(sizeof(char *) * (count_words(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			j = 0;
			if (!(ret[k] = malloc(sizeof(char) * (get_size(s, c, i) + 1))))
				return (freeall(ret, k));
			while (s[i] != c && s[i])
				ret[k][j++] = s[i++];
			ret[k++][j] = '\0';
		}
	}
	ret[k] = NULL;
	return (ret);
}
