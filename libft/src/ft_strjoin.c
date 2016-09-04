/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 19:45:53 by rbaum             #+#    #+#             */
/*   Updated: 2015/02/21 21:55:52 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l;
	char	*str;

	if (s1 != NULL && s2 != NULL)
	{
		l = ft_strlen(s1) + ft_strlen(s2);
		str = ft_strnew(l);
		if (!str || !s1 || !s2)
			return (NULL);
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
		return (str);
	}
	return (0);
}
