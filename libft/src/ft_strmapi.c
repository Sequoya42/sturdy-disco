/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 17:15:51 by rbaum             #+#    #+#             */
/*   Updated: 2014/11/13 17:15:55 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	i;
	unsigned int	l;
	char			*str;

	if (s != NULL && f != NULL)
	{
		i = 0;
		l = ft_strlen(s);
		str = ft_strnew(l);
		while (i < l)
		{
			str[i] = (*f)(i, s[i]);
			i++;
		}
		return (str);
	}
	return (NULL);
}
