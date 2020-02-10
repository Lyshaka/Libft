/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-abovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:41:44 by md-abovi          #+#    #+#             */
/*   Updated: 2019/10/08 13:41:47 by md-abovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src_tmp;
	char	*dst_tmp;
	size_t	i;

	src_tmp = (char *)src;
	dst_tmp = (char *)dst;
	i = 0;
	if (src_tmp == dst_tmp)
		return (dst);
	if (src_tmp < dst_tmp)
		while (len-- > 0)
			*((char *)dst_tmp + len) = *((char *)src_tmp + len);
	else
		while (i < len)
		{
			*((char *)dst + i) = *((char *)src + i);
			i++;
		}
	return (dst);
}
