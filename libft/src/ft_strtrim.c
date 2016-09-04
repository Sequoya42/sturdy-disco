/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 15:14:11 by rbaum             #+#    #+#             */
/*   Updated: 2014/11/14 20:59:37 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_none(char c)
{
	if (c == '\n' || c == '\t' || c == ' ' || c == '\f' || c == '\v')
		return (c);
	return (0);
}

char			*ft_strtrim(const char *s)
{
	char		*str;
	int			i;
	size_t		l;

	l = 0;
	if (s != NULL)
	{
		while (ft_none(*s) != 0)
			s++;
		while (s[l] != '\0')
		{
			i = 0;
			while (ft_none(s[i + l]) != 0)
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

char			*ft_strtrim_all(const char *s)
{
	char		*str;
	int			i;
	size_t		l;

	l = 0;
	i = 0;
	str = ft_strnew(ft_strlen(s));
	if (s != NULL)
	{
		while (s[i])
		{
			if (!ft_none(s[i]))
				str[l++] = s[i];
			i++;
		}
		return (str);
	}
	return (NULL);
}
