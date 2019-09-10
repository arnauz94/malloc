/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:46:45 by avinas            #+#    #+#             */
/*   Updated: 2017/11/16 19:45:57 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_isspace(int c)
{
	return ((9 <= c && c <= 13) || c == 32);
}

char			*ft_strtrim(char const *s)
{
	int				fin;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	fin = (int)ft_strlen((char*)s) - 1;
	while (ft_isspace(s[i]) && s[i])
		i++;
	while (ft_isspace(s[fin]) && s[fin] && fin > (int)i)
		fin--;
	return (ft_strsub(s, i, (fin - i + 1)));
}
