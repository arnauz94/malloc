/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:14:05 by avinas            #+#    #+#             */
/*   Updated: 2017/12/09 22:00:34 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*ret;
	size_t	cpt;

	cpt = 0;
	ret = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (cpt != n && *src)
	{
		*dest = *src;
		src++;
		dest++;
		cpt++;
	}
	*dest = '\0';
	return (&ret[0]);
}
