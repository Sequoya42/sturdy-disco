/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 18:48:15 by rbaum             #+#    #+#             */
/*   Updated: 2015/01/02 18:54:03 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list *tmp;

	if (new)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			tmp = *alst;
			*alst = new;
			(*alst)->next = tmp;
		}
	}
}
