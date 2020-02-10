/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-abovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:44:15 by md-abovi          #+#    #+#             */
/*   Updated: 2019/11/14 19:44:18 by md-abovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size(long nbr)
{
	int		size;

	size = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		size++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	int		i;
	long	nbr;
	char	*ret;

	i = size(n);
	nbr = n;
	if (!(ret = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ret[i--] = 0;
	if (nbr == 0)
		return (ft_strdup("0"));
	if (nbr < 0)
	{
		ret[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		ret[i--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (ret);
}
