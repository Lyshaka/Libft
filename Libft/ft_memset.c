/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-abovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:32:21 by md-abovi          #+#    #+#             */
/*   Updated: 2019/10/07 15:32:22 by md-abovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void				*ft_memset(void *b, int c, unsigned int len)
{
	unsigned int	i;
	unsigned char	*temp;

	i = 0;
	temp = b;
	while (i < len)
	{
		temp[i] = (unsigned char)c;
		i++;
	}
	b = temp;
	return (b);
}
