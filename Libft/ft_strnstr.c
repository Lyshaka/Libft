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

#include <stddef.h>

char		*ft_strnstr(const char *big, const char *lit, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	lit_size;

	i = 0;
	j = 0;
	lit_size = 0;
	while (lit[lit_size])
		lit_size++;
	if (*lit == 0)
		return ((char*)big);
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
