/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 17:52:55 by avinas            #+#    #+#             */
/*   Updated: 2018/05/18 15:43:19 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*tmp1;
	const unsigned char	*tmp2;

	tmp1 = (const unsigned char*)s1;
	tmp2 = (const unsigned char*)s2;
	if (s1 == s2 || n == 0)
		return (0);
	while (n--)
	{
		if (*tmp1 != *tmp2)
			return (*tmp1 - *tmp2);
		if (n)
		{
			tmp1++;
			tmp2++;
		}
	}
	return (0);
}
