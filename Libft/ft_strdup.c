/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-abovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:28:17 by md-abovi          #+#    #+#             */
/*   Updated: 2019/10/15 16:29:16 by md-abovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strdup(const char *s)
{
	int		i;
	char	*ret;

	i = 0;
	while (s[i])
		i++;
	if (!(ret = malloc(sizeof(char) * i)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		ret[i] = s[i];
		i++;
	}
	return (ret);
}
