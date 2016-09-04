/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 18:49:59 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/23 13:45:06 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *list, t_list *(*f)(t_list*))
{
	t_list	*maped;
	t_list	*add;
	t_list	*tmp;

	if (list == NULL)
		return (NULL);
	maped = f(list);
	tmp = maped;
	list = list->next;
	while (list != NULL)
	{
		add = f(list);
		tmp->next = add;
		tmp = add;
		list = list->next;
	}
	return (maped);
}
