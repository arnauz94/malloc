/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 00:57:16 by avinas            #+#    #+#             */
/*   Updated: 2017/11/20 01:17:55 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_sort_integer_table(int *tab, int size)
{
	int cpt;
	int temp;

	if (!tab)
		return (NULL);
	cpt = 0;
	while (cpt < size)
	{
		if (tab[cpt] > tab[cpt + 1] && cpt < size - 1)
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
