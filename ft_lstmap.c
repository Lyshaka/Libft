/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-abovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:08:43 by md-abovi          #+#    #+#             */
/*   Updated: 2019/11/21 18:08:44 by md-abovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;

	if (!(new = ft_lstnew(lst->content)))
		return (NULL);
	while (lst)
	{
		ft_lstiter(new, f(new->content));
		lst = lst->next;
	}
	return (new);
}
