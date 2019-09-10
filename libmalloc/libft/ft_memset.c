/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:12:06 by avinas            #+#    #+#             */
/*   Updated: 2017/11/13 17:50:05 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*d;
	unsigned long	cpt;

	cpt = 0;
	d = (unsigned char*)b;
	while (cpt < len)
	{
		*d++ = (unsigned char)c;
		cpt++;
	}
	return (b);
}
