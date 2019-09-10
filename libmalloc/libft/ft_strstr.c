/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 18:10:10 by avinas            #+#    #+#             */
/*   Updated: 2017/12/20 16:20:12 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int cpt_str;
	int cpt_find;

	cpt_str = 0;
	if (ft_strcmp(to_find, "") == 0)
		return ((char*)str);
	while (str[cpt_str] != '\0')
	{
		cpt_find = 0;
		while (to_find[cpt_find] == str[cpt_str + cpt_find])
		{
			if (to_find[cpt_find + 1] == '\0')
				return ((char*)str + cpt_str);
			cpt_find++;
		}
		cpt_str++;
	}
	return (0);
}
