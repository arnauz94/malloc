/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:07:14 by avinas            #+#    #+#             */
/*   Updated: 2017/11/19 23:40:43 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t length)
{
	size_t	cpt_str;
	size_t	cpt_find;
	char	*ret;

	cpt_str = 0;
	ret = (char*)str;
	if (ft_strcmp(to_find, "") == 0)
		return (ret);
	while (str[cpt_str] != '\0')
	{
		cpt_find = 0;
		while (to_find[cpt_find] == str[cpt_str + cpt_find])
		{
			if (to_find[cpt_find + 1] == '\0' && cpt_find + cpt_str < length)
				return (ret + cpt_str);
			cpt_find++;
		}
		cpt_str++;
	}
	return (0);
}
