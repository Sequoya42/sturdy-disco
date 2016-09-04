/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:21:10 by rbaum             #+#    #+#             */
/*   Updated: 2014/11/12 14:49:39 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	str = s1;
	while (str[i] != '\0')
		i++;
	while (j < n)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (s1);
}
