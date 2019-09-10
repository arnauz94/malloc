/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:37:15 by avinas            #+#    #+#             */
/*   Updated: 2017/11/16 15:07:46 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	while (n--)
	{
		*(unsigned char*)d++ = *(unsigned char*)s;
		if (*(unsigned char*)s++ == (unsigned char)c)
			return (d);
	}
	return (NULL);
}
