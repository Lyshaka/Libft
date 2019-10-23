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

#include <stddef.h>

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;

	i = 0;
	if (dst < src && (src + len) > dst)
	{
		i = len;
		while (i-- > 0)
			*((unsigned char *)dst + i) = *((unsigned char *)src + i);
	}
	else
	{
		while (i < len)
		{
			*((unsigned char *)dst + i) = *((unsigned char *)src + i);
			i++;
		}
	}
	return (dst);
}
