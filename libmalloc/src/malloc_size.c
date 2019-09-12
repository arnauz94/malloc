/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <avinas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:34:23 by avinas            #+#    #+#             */
/*   Updated: 2019/09/12 16:24:01 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libmalloc.h"
#include "../include/page_manager.h"
#include "../include/allocator.h"
#include "../include/utils_type.h"

size_t	malloc_size(const void *ptr)
{
	t_page *ret;

	ret = *getfirstpage();
	if (ret == NULL)
		return (0);
	while (ret)
	{
		if (ret->data == ptr && !ret->isfree)
		{
			return (ret->size);
		}
		ret = ret->next;
	}
	return (0);
}

size_t	malloc_good_size(size_t size)
{
	return (ALIGN16(size));
}
