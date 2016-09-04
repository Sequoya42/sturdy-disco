/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:10:09 by rbaum             #+#    #+#             */
/*   Updated: 2014/11/14 20:59:19 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int i;
	int diff;

	i = 0;
	if (s1 != NULL && s2 != NULL)
	{
		while (s2[i] || s1[i])
		{
			diff = (s1[i] - s2[i]);
			if (diff != 0)
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}
