/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 22:37:25 by avinas            #+#    #+#             */
/*   Updated: 2017/12/09 22:35:13 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_strdup(const char *src)
{
	int		length;
	char	*ret;
	int		cpt;

	cpt = 0;
	length = ft_strlen(src);
	ret = malloc(sizeof(char) * length + 1);
	if (ret == NULL)
		return (NULL);
	while (cpt < length)
	{
		ret[cpt] = src[cpt];
		cpt++;
	}
	ret[cpt] = '\0';
	return (ret);
}
