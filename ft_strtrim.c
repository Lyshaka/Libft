/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-abovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 06:11:53 by md-abovi          #+#    #+#             */
/*   Updated: 2019/11/12 06:11:55 by md-abovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isset(char const *set, char c)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	get_size(char const *str, char const *set, int *i, int *j)
{
	int		size;

	size = ft_strlen(str);
	while (isset(set, str[(*i)]))
		(*i)++;
	while (isset(set, str[size - (*j) - 1]) && size != (*i))
		(*j)++;
	while (isset(set, str[size - (*j)]) && size == (*i))
		(*j)++;
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	int		size;
	char	*ret;

	i = 0;
	j = 0;
	k = 0;
	if (!s1 || !set)
		return (NULL);
	size = ft_strlen(s1);
	get_size(s1, set, &i, &j);
	if (!(ret = malloc(sizeof(char) * ((size - (i + j) + 1)))))
		return (NULL);
	while (k < size - (i + j))
	{
		ret[k] = s1[k + i];
		k++;
	}
	ret[k] = 0;
	return (ret);
}
