/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-abovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:45:42 by md-abovi          #+#    #+#             */
/*   Updated: 2019/10/09 15:45:43 by md-abovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

unsigned int		ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	src_size;
	unsigned int	dst_size;

	i = 0;
	src_size = 0;
	dst_size = 0;
	while (src[src_size])
		src_size++;
	while (dst[dst_size])
		dst_size++;
	if (dst_size > size)
		return (src_size + size);
	while (i < size - 1)
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst_size + src_size);
}
