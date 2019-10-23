/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-abovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:57:59 by md-abovi          #+#    #+#             */
/*   Updated: 2019/10/10 15:58:01 by md-abovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

void				*ft_calloc(size_t count, size_t size)
{
	void			*ret;
	int	unsigned	i;
	int	unsigned	j;

	if (!(ret = malloc(count * size)))
		return (NULL);
	i = 0;
	j = 0;
	while (i <= count)
	{
		while (j < size)
		{
			*((char*)(ret + i + j)) = 0;
			j++;
		}
		i++;
	}
	return (ret);
}
