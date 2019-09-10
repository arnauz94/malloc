/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:24:48 by avinas            #+#    #+#             */
/*   Updated: 2017/12/20 17:21:16 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned long	cpt;

	cpt = 0;
	if ((int)len < 0 || !s)
		return (NULL);
	ret = (char*)malloc(sizeof(char) * len + 1);
	if (ret == NULL)
		return (NULL);
	while (cpt < len)
	{
		ret[cpt] = s[cpt + start];
		cpt++;
	}
	ret[cpt] = '\0';
	return (ret);
}
