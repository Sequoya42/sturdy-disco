/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 07:34:42 by rbaum             #+#    #+#             */
/*   Updated: 2015/02/22 20:56:29 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_split_char(char *s, int i, char c)
{
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (s[i] != c)
		i++;
	tmp = ft_strnew(i);
	ft_strncpy(tmp, s, i);
	return (tmp);
}
