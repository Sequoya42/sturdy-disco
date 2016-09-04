/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 18:15:58 by rbaum             #+#    #+#             */
/*   Updated: 2015/02/12 22:57:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (s != NULL)
	{
		if ((str = ft_strnew(len + 1)) == NULL)
			return (NULL);
		while (i < len)
		{
			str[i] = s[start];
			i++;
			start++;
		}
		return (str);
	}
	return (0);
}
