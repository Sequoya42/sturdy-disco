/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:52:39 by rbaum             #+#    #+#             */
/*   Updated: 2015/02/09 13:28:16 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_caract(const char *str)
{
	int		i;

	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\r' ||
str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '+' && ft_isdigit(str[i + 1]) != 0)
		i++;
	return (i);
}

int				ft_atoi(const char *str)
{
	int		i;
	int		res;
	int		neg;

	i = ft_caract(str);
	neg = 0;
	res = 0;
	if (str[i] == '-' && ft_isdigit(str[i + 1]) != 0)
	{
		neg++;
		i++;
	}
	while (ft_isdigit(str[i]) != 0)
	{
		res = res * 10;
		res = res + (str[i] - 48);
		i++;
	}
	return (neg == 1 ? -res : res);
}

long			ft_atol(const char *str)
{
	int		i;
	long	res;
	int		neg;

	i = ft_caract(str);
	neg = 0;
	res = 0;
	if (str[i] == '-' && ft_isdigit(str[i + 1]) != 0)
	{
		neg++;
		i++;
	}
	while (ft_isdigit(str[i]) != 0)
	{
		res = res * 10;
		res = res + (str[i] - 48);
		i++;
	}
	return (neg == 1 ? -res : res);
}
