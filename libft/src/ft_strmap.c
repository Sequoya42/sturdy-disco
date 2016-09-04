/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 16:31:30 by rbaum             #+#    #+#             */
/*   Updated: 2014/11/13 17:17:16 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	size_t	i;
	size_t	l;
	char	*str;

	if (s != NULL && f != NULL)
	{
		i = 0;
		l = ft_strlen(s);
		str = ft_strnew(l);
		while (i < l)
		{
			str[i] = (*f)(s[i]);
			i++;
		}
		return (str);
	}
	return (NULL);
}
