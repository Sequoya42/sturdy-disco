/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 07:50:24 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/23 13:43:51 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_error(char *name, char *arg, char *msg)
{
	if (name != NULL)
	{
		ft_putstr_fd(name, 2);
		ft_putstr_fd(": ", 2);
	}
	if (arg != NULL)
	{
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putendl_fd(msg, 2);
	return (-1);
}

void	ft_exit(char *name, char *arg, char *msg)
{
	if (name != NULL)
	{
		ft_putstr_fd(name, 2);
		ft_putstr_fd(": ", 2);
	}
	if (arg != NULL)
	{
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putendl_fd(msg, 2);
	exit(-1);
}

void	ft_colstr(char *col, char *msg)
{
	ft_putstr(col);
	ft_putstr(msg);
	ft_putstr(KNRM);
}

void	ft_colendl(char *s)
{
	ft_putstr(KGRN);
	ft_putendl(s);
	ft_putstr(KNRM);
}

void	ft_strcol(char *col, char *o, char *t, char *l)
{
	if (o)
		ft_putstr(o);
	ft_putstr(col);
	ft_putstr(t);
	ft_putstr(KNRM);
	if (l)
		ft_putstr(l);
}
