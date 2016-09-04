/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:41:41 by rbaum             #+#    #+#             */
/*   Updated: 2014/11/14 20:57:44 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*str;
	int		save;
	int		neg;
	int		i;

	save = n;
	neg = (n < 0 ? -1 : 1);
	i = 1 + (n < 0);
	while (n /= 10)
		i++;
	if (!(str = ft_strnew(i)))
		return (NULL);
	str[i--] = '\0';
	str[i--] = neg * (save % 10) + 48;
	while (save /= 10)
		str[i--] = neg * (save % 10) + 48;
	if (neg < 0)
		str[i] = '-';
	return (str);
}
