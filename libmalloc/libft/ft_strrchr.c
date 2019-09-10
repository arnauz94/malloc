/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:16:41 by avinas            #+#    #+#             */
/*   Updated: 2017/11/19 23:42:02 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *ret;

	ret = NULL;
	while (*str)
	{
		if (((int)*str) == c)
		{
			ret = (char*)str;
		}
		str++;
	}
	if (c == (int)'\0')
		ret = (char*)str;
	return (ret);
}
