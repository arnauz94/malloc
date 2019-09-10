/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:35:45 by avinas            #+#    #+#             */
/*   Updated: 2017/11/16 15:19:19 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*ret;

	ret = (void*)malloc(sizeof(void) * size);
	if (ret == NULL)
		return (NULL);
	ft_memset(ret, 0, size);
	return (ret);
}
