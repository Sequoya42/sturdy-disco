/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 19:12:18 by rbaum             #+#    #+#             */
/*   Updated: 2015/02/14 19:16:06 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int i)
{
	int		l;
	int		j;
	char	*s2;

	l = 0;
	if (!s1)
		return (NULL);
	while (s1[l])
		l++;
	s2 = ft_strnew(l + 1);
	j = 0;
	while (j < i)
	{
		s2[j] = s1[j];
		j++;
	}
	s2[j] = '\0';
	return (s2);
}
