/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 21:27:40 by avinas            #+#    #+#             */
/*   Updated: 2017/11/16 14:32:26 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static inline void	loop_forward_fn(void *dst, const void *src, size_t n)
{
	src += n;
	dst += n;
	while (n)
	{
		dst--;
		src--;
		*(char *)dst = *(char *)src;
		n--;
	}
}

static inline void	loop_backward_fn(void *dst, const void *src, size_t n)
{
	while (n)
	{
		*(char *)dst = *(char *)src;
		dst++;
		src++;
		n--;
	}
}

void				*ft_memmove(void *dst, const void *src, size_t n)
{
	if (n == 0 || dst == src)
		return (dst);
	if (src > dst)
		loop_backward_fn(dst, src, n);
	else
		loop_forward_fn(dst, src, n);
	return (dst);
}
