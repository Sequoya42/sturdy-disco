/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:36:52 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/21 17:51:10 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int			i;
	int			j;
	char		*s2;

	i = 0;
	if (!s1)
		return (NULL);
	while (s1[i])
		i++;
	if ((s2 = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	j = 0;
	while (s1[j])
	{
		s2[j] = s1[j];
		j++;
	}
	s2[j] = '\0';
	return (s2);
}
