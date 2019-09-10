/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:43:06 by avinas            #+#    #+#             */
/*   Updated: 2017/11/16 19:39:19 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char *s, char (*f) (unsigned int, char))
{
	char	*ret;
	int		cpt;
	int		size;

	cpt = 0;
	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	ret = (char*)malloc(sizeof(char) * size + 1);
	if (ret == NULL)
		return (NULL);
	while (cpt < size)
	{
		ret[cpt] = f(cpt, s[cpt]);
		cpt++;
	}
	ret[cpt] = '\0';
	return (ret);
}
