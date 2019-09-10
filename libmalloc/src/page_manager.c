/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <avinas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:40:12 by avinas            #+#    #+#             */
/*   Updated: 2019/08/31 15:19:18 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/allocator.h"
#include "../include/utils_type.h"

t_page	**getfirstpage(void)
{
	static t_page	*first = NULL;

	return (&first);
}

t_page	*getnextpage(t_page *page)
{
	page = page->next;
	while (page != NULL)
	{
		if (page->type % 2 == 0)
			return (page);
		page = page->next;
	}
	return (NULL);
}

t_page	*getprevpage(t_page *page)
{
	page = page->prev;
	while (page != NULL)
	{
		if (page->type % 2 == 0)
			return (page);
		page = page->prev;
	}
	return (NULL);
}

t_page	*searchfreepage(size_t size)
{
	t_page *ret;

	ret = *getfirstpage();
	if (ret == NULL)
		return (NULL);
	while (ret != NULL)
	{
		if (ret->size > size + sizeof(t_page) && ret->isfree
			&& (ret->type == get_type(size) - 1))
		{
			return (ret);
		}
		ret = ret->next;
	}
	return (NULL);
}

void	*createpage(size_t size)
{
	t_page	*ret;
	t_page	*first;
	size_t	size_page;
	int		type;

	first = *getfirstpage();
	type = get_type(size);
	size_page = get_mypage_size(size);
	ret = mmap(0, size_page, PROT_READ | PROT_WRITE,
			MAP_PRIVATE | MAP_ANON, -1, 0);
	ret->size = size_page - sizeof(t_page);
	if (ret == MAP_FAILED)
		return (NULL);
	ret->data = ret + 1;
	ret->isfree = 0;
	ret->type = type;
	ret->next = first;
	if (first != NULL)
		first->prev = ret;
	*getfirstpage() = ret;
	return (first_alloc(*getfirstpage(), ret->size));
}
