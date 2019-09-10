/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <avinas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 18:13:13 by avinas            #+#    #+#             */
/*   Updated: 2019/09/10 18:47:57 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libmalloc.h"
#include "../include/page_manager.h"

int		is_alloc(t_page *page)
{
	page = page->next;
	while (page != NULL)
	{
		if (page->type % 2 == 0)
			return (0);
		if (page->isfree == 0)
			return (1);
		page = page->next;
	}
	return (0);
}

void	remove_empty_page(t_page *ret)
{
	t_page *nextpage;

	while (ret->type % 2 != 0)
	{
		ret = ret->prev;
	}
	if (is_alloc(ret) == 0)
	{
		nextpage = getnextpage(ret);
		if (*getfirstpage() == ret)
		{
			nextpage->prev = NULL;
			*getfirstpage() = nextpage;
		}
		else
		{
			if (nextpage != NULL)
				nextpage->prev = ret->prev;
			ret->prev->next = nextpage;
		}
		munmap(ret, (ret->size + sizeof(t_page)));
	}
}

t_page	*defrag(t_page *ret)
{
	if (ret->prev->isfree == 1)
	{
		ret->prev->size += ret->size + sizeof(t_page);
		ret->prev->next = ret->next;
		ret->next->prev = ret->prev;
		ret = ret->prev;
	}
	if (ret->next != NULL)
	{
		if (ret->next->isfree == 1)
		{
			ret->size += ret->next->size + sizeof(t_page);
			ret->next = ret->next->next;
			if (ret->next != NULL)
				ret->next->prev = ret;
		}
	}
	return (ret);
}

void	free(void *ptr)
{
	t_page *ret;

	if (ptr == NULL)
		return ;
	ret = *getfirstpage();
	if (ret == NULL)
		return ;
	while (ret != NULL)
	{
		if (ret->data == ptr && !ret->isfree)
		{
			ret = defrag(ret);
			ret->isfree = 1;
			remove_empty_page(ret);
			return ;
		}
		ret = ret->next;
	}
}
