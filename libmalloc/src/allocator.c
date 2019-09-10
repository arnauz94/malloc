/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <avinas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 12:51:08 by avinas            #+#    #+#             */
/*   Updated: 2019/08/20 19:25:37 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/allocator.h"
#include "../include/page_manager.h"

void	*first_alloc(t_page *page, size_t size)
{
	t_page *new;

	new = (t_page*)page->data;
	if (page->next != NULL)
		page->next->prev = new;
	new->next = page->next;
	new->prev = page;
	page->next = new;
	new->type = page->type - 1;
	new->size = size - sizeof(t_page);
	new->data = new + 1;
	new->isfree = 1;
	return (new->data);
}

void	*alloc(t_page *block, size_t size)
{
	t_page *new;

	new = (t_page*)(block->data + size);
	new->data = new + 1;
	new->type = block->type;
	if (block->next != NULL)
		block->next->prev = new;
	new->prev = block;
	new->next = block->next;
	new->size = block->size;
	new->size = block->size - size - sizeof(t_page);
	new->isfree = block->isfree;
	block->next = new;
	block->size = size;
	block->isfree = 0;
	return (block->data);
}
