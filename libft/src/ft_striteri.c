/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 16:19:20 by rbaum             #+#    #+#             */
/*   Updated: 2014/11/13 17:38:33 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f) (unsigned int, char *))
{
	int i;
	int l;

	i = 0;
	if (s != NULL && f != NULL)
	{
		l = ft_strlen(s);
		while (i < l)
		{
			f(i, &s[i]);
			i++;
		}
	}
}
