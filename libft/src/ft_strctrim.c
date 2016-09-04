/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 14:20:11 by rbaum             #+#    #+#             */
/*   Updated: 2014/11/14 14:25:41 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strctrim(const char *s, char c)
{
	char	*str;
	int		i;
	size_t	l;

	l = 0;
	if (s != NULL)
	{
		while (*s == c)
			s++;
		while (s[l] != '\0')
		{
			i = 0;
			while (s[i + l] == c)
				i++;
			if (i > 0 && s[i + l] == '\0')
				break ;
			else if (i > 0)
				l = l + i;
			l++;
		}
		str = ft_strnew(l);
		ft_memcpy(str, s, l);
		return (str);
	}
	return (NULL);
}
