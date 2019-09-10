/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 12:21:48 by avinas            #+#    #+#             */
/*   Updated: 2017/11/19 23:35:16 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*cs1;
	unsigned char	*cs2;

	cs1 = (unsigned char*)s1;
	cs2 = (unsigned char*)s2;
	while (n--)
	{
		if (*cs1 != *cs2)
			return (*cs1 - *cs2);
		if (*cs1 == '\0' && *cs2 == '\0')
			return (0);
		cs1++;
		cs2++;
	}
	return (0);
}
