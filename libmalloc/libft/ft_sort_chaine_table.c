/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_chaine_table.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 01:15:38 by avinas            #+#    #+#             */
/*   Updated: 2017/11/20 01:20:55 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sort_chaine_table(char **tab, int size)
{
	int		cpt;
	char	*temp;

	if (!tab)
		return (NULL);
	temp = NULL;
	cpt = 0;
	while (cpt < size)
	{
		if (ft_strcmp((const char*)tab[cpt],
		(const char*)tab[cpt + 1]) < 0 && cpt < size - 1)
		{
			temp = tab[cpt];
			tab[cpt] = tab[cpt + 1];
			tab[cpt + 1] = temp;
			cpt = 0;
		}
		else
		{
			cpt++;
		}
	}
	return (tab);
}
