/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 18:03:32 by rbaum             #+#    #+#             */
/*   Updated: 2015/03/16 18:33:24 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strdup_tab(char **tab)
{
	char	**tmp;
	int		i;

	if (tab == NULL)
		return (NULL);
	i = ft_nb_tab(tab);
	tmp = malloc(sizeof(*tmp) * (i + 1));
	i = 0;
	while (tab[i])
	{
		tmp[i] = ft_strdup(tab[i]);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}
