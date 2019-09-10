/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 21:31:22 by avinas            #+#    #+#             */
/*   Updated: 2017/11/16 15:08:53 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*d;
	unsigned long	cpt;

	d = (unsigned char*)s;
	cpt = 0;
	while (cpt < n)
	{
		if (d[cpt] == (unsigned char)c)
			return ((void*)&s[cpt]);
		cpt++;
	}
	return (NULL);
}
