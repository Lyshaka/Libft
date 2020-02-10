/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-abovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:47:18 by md-abovi          #+#    #+#             */
/*   Updated: 2019/10/09 16:47:20 by md-abovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lit_size;

	i = 0;
	lit_size = 0;
	while (lit[lit_size])
		lit_size++;
	if (*lit == 0)
		return ((char*)big);
	if (len == 0)
		return (0);
	while (big[i] && i < len - lit_size + 1)
	{
		j = 0;
		if (big[i] == lit[j])
		{
			while (big[i + j] == lit[j] && lit[j] != 0)
				j++;
			if (lit[j] == 0)
				return ((char*)(big + i));
		}
		i++;
	}
	return (0);
}
