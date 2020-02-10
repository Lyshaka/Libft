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

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ret;
	size_t	dst_size;
	size_t	i;

	dst_size = 0;
	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dst[dst_size] && dst_size < size)
		dst_size++;
	if ((size - 1) < dst_size)
		ret = ft_strlen(src) + size;
	else
		ret = ft_strlen(src) + dst_size;
	if (dst_size < size)
	{
		while (src[i] && dst_size < size - 1)
			dst[dst_size++] = src[i++];
		dst[dst_size] = 0;
	}
	return (ret);
}
