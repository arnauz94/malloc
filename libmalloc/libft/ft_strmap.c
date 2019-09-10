/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:34:35 by avinas            #+#    #+#             */
/*   Updated: 2017/11/16 19:38:58 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char *s, char (*f) (char))
{
	char	*ret;
	int		size;
	int		cpt;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	cpt = 0;
	ret = (char*)malloc(sizeof(char) * size + 1);
	if (ret == NULL)
		return (NULL);
	while (cpt < size)
	{
		ret[cpt] = f(s[cpt]);
		cpt++;
	}
	ret[cpt] = '\0';
	return (ret);
}
