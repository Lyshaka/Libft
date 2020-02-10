/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-abovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 06:42:48 by md-abovi          #+#    #+#             */
/*   Updated: 2019/11/12 06:42:49 by md-abovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		size1;
	int		size2;
	char	*ret;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if (!(ret = malloc(sizeof(char) * (size1 + size2 + 1))))
		return (NULL);
	while (i < size1)
	{
		ret[i] = s1[i];
		i++;
	}
	while (i < (size1 + size2))
	{
		ret[i] = s2[i - size1];
		i++;
	}
	ret[i] = 0;
	return (ret);
}
