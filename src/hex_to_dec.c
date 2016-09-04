/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 18:33:43 by rbaum             #+#    #+#             */
/*   Updated: 2016/09/04 18:33:47 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int							ft_exp(int f, int l)
{
	int						r;

	r = 1;
	while (l--)
		r *= f;
	return (r);
}

int							hex_to_dec(unsigned int n)
{
	int						r;
	int						l;
	int						k;

	l = 0;
	r = 0;
	while (n)
	{
		k = (n % 10);
		r += k * ft_exp(16 , l);
		l++;
		n /= 10;
	}
	return (r);
}
