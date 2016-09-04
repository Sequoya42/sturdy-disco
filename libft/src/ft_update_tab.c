/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 07:42:22 by rbaum             #+#    #+#             */
/*   Updated: 2015/02/22 23:05:46 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_update_tab(char **tab)
{
	int		i;
	int		k;
	char	**tmp;

	i = 0;
	k = 0;
	if (tab == NULL)
		return (NULL);
	while (tab[i])
	{
		if (tab[i][0] == '\0')
			k++;
		i++;
	}
	if ((tmp = malloc(sizeof(*tab) * (i - k) + 1)) == NULL)
		ft_error(NULL, NULL, NULL);
	return (tmp);
}
