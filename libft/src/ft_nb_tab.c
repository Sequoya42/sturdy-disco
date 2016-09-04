/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 19:56:26 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/16 18:40:23 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_nb_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void		ft_print_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		ft_putendl(tab[i++]);
}

void		ft_trim_tab(char **tab)
{
	int		i;
	char	*t;

	i = 0;
	while (tab[i])
	{
		t = tab[i];
		tab[i] = ft_strtrim(tab[i]);
		free(t);
		i++;
	}
}

void		ft_init_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		tab[i] = NULL;
		++i;
	}
	tab[i] = NULL;
}
