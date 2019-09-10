/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 23:56:35 by avinas            #+#    #+#             */
/*   Updated: 2017/12/09 23:07:44 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	ret = ft_strnew(size + 1);
	if (ret == NULL)
		return (NULL);
	ft_strcpy(ret, (char*)s1);
	ft_strcat(ret, (char*)s2);
	ret[size] = '\0';
	return (ret);
}
