/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:26:10 by avinas            #+#    #+#             */
/*   Updated: 2017/11/12 18:37:47 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*d;
	char			*s;
	unsigned long	cpt;

	s = (char*)src;
	d = dst;
	cpt = 0;
	while (cpt < n)
	{
		d[cpt] = s[cpt];
		cpt++;
	}
	return (dst);
}
