/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:48:36 by avinas            #+#    #+#             */
/*   Updated: 2017/12/10 04:04:26 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char *ret;

	ret = "\0";
	while (*str && *str != (unsigned char)c)
	{
		str++;
	}
	if (*str == (unsigned char)c)
		return ((char*)str);
	return (NULL);
}
