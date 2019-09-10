/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:48:35 by avinas            #+#    #+#             */
/*   Updated: 2017/11/13 23:58:23 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char			*ret;
	unsigned long	cpt;

	cpt = 0;
	ret = (char*)malloc(sizeof(char) * size + 1);
	if (ret == NULL)
		return (NULL);
	ret = ft_memset(ret, 0, size);
	ret[size] = '\0';
	return (ret);
}
