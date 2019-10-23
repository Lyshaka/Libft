/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-abovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 23:55:18 by md-abovi          #+#    #+#             */
/*   Updated: 2019/10/23 23:55:22 by md-abovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*ret;

	i = 0;
	if (!(ret = malloc(sizeof(char) * len)))
		return (NULL);
	while (i < len || s[i])
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}
