/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 18:48:44 by rbaum             #+#    #+#             */
/*   Updated: 2015/01/05 17:09:45 by edgaunt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*temp;

	temp = (void *)ft_memalloc(content_size + 1);
	if (content == NULL)
	{
		temp = NULL;
		content_size = 0;
	}
	else
		temp = ft_memcpy(temp, content, content_size);
	new = (t_list *)ft_memalloc(sizeof(t_list));
	if (new != (t_list *)NULL)
	{
		new->content_size = content_size;
		new->next = NULL;
		new->content = temp;
	}
	return (new);
}
