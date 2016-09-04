/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:43:26 by rbaum             #+#    #+#             */
/*   Updated: 2014/11/14 19:36:08 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	int		i;
	char	*t;

	i = 0;
	if (c == 0)
		return ((char *)&s[ft_strlen(s)]);
	t = (char *)s;
	while (t[i])
	{
		if (t[i] == (char)c)
			return (t + i);
		i++;
	}
	return (NULL);
}
