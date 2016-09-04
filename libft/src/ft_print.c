/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 17:06:29 by rbaum             #+#    #+#             */
/*   Updated: 2016/08/23 17:06:34 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

void				ft_print(char *s, ...)
{
	int				i;
	char			*t;
	va_list			argp;

	i = 0;
	t = s;
	va_start(argp, s);
	while (t[i])
	{
		if (t[i] != '%')
			ft_putchar(t[i]);
		else
		{
			if (t[i + 1] == 'd')
				ft_putnbr(va_arg(argp, int));
			else if (t[i + 1] == 's')
				ft_putstr(va_arg(argp, char *));
			i++;
		}
		i++;
	}
	va_end(argp);
}

void				msg_exit(char *s, ...)
{
	int				i;
	char			*t;
	va_list			argp;

	i = 0;
	t = s;
	va_start(argp, s);
	while (t[i])
	{
		if (t[i] != '%')
			ft_putchar(t[i]);
		else
		{
			if (t[i + 1] == 'd')
				ft_putnbr(va_arg(argp, int));
			else if (t[i + 1] == 's')
				ft_putstr(va_arg(argp, char *));
			i++;
		}
		i++;
	}
	va_end(argp);
	exit(0);
}
