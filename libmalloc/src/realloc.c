/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <avinas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:42:06 by avinas            #+#    #+#             */
/*   Updated: 2019/09/12 16:34:56 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libmalloc.h"
#include "../include/page_manager.h"
#include "../include/allocator.h"
#include "../include/utils_type.h"

t_page	*getactualblock(void *ptr)
{
	t_page *ret;

	ret = *getfirstpage();
	if (ret == NULL)
		return (NULL);
	while (ret)
	{
		if (ret->data == ptr && !ret->isfree)
		{
			return (ret);
		}
		ret = ret->next;
	}
	free(ptr);
	return (NULL);
}

t_page	*smaller(t_page *actual, size_t size)
{
	void	*ret;

	ret = alloc(actual, size);
	free(actual->next->data);
	return (ret);
}

t_page	*anotherplace(t_page *actual, size_t size)
{
	t_page	*ret;

	if ((ret = malloc(size)) == NULL)
		return (NULL);
	if (actual->size < size)
		ret = ft_memcpy(ret, actual->data, actual->size);
	else
		ret = ft_memcpy(ret, actual->data, size);
	free(actual->data);
	return (ret);
}

void	*ft_realloc(void *ptr, size_t size)
{
	t_page *actual;

	size = ALIGN16(size);
	if (ptr == NULL)
		return (malloc(size));
	if ((actual = getactualblock(ptr)) == NULL)
		return (NULL);
	if (actual->size > size)
		return (smaller(actual, size));
	if (get_type(actual->size) != get_type(size))
		return (anotherplace(actual, size));
	if (actual->next == NULL)
		return (anotherplace(actual, size));
	if (!actual->next->isfree || actual->size + actual->next->size + 1 < size)
		return (anotherplace(actual, size));
	if (actual->next != NULL)
		if (actual->next->isfree == 1)
		{
			actual->size += actual->next->size + sizeof(t_page);
			actual->next = actual->next->next;
			if (actual->next != NULL)
				actual->next->prev = actual;
		}
	return (alloc(actual, size));
}

void	*realloc(void *ptr, size_t size)
{
	pthread_mutex_lock(&g_mutex);
	ptr = ft_realloc(ptr, size);
	pthread_mutex_unlock(&g_mutex);
	return (ptr);
}
