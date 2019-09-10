/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <avinas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:47:38 by avinas            #+#    #+#             */
/*   Updated: 2019/08/31 15:20:02 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/page_manager.h"
#include "../include/utils_type.h"

static void	put_block(t_page *block)
{
	ft_putaddr(block->data);
	ft_putstr(" - ");
	ft_putaddr(block->data + block->size);
	ft_putstr(" : ");
	ft_putnbr(block->size);
	ft_putstr(" octets");
}

void		show_page(t_page *page)
{
	if (page == NULL)
		return ;
	page = page->next;
	while (page != NULL)
	{
		if (page->type % 2 == 0)
			break ;
		if (!page->isfree)
		{
			put_block(page);
			ft_putstr("\n");
		}
		page = page->next;
	}
}

void		show_alloc_mem(void)
{
	t_page *page;

	page = *getfirstpage();
	if (page == NULL)
		return ;
	while (page->next != NULL)
	{
		page = page->next;
	}
	page = getprevpage(page);
	while (page != NULL)
	{
		if (page->type == 4)
			ft_putstr("TINY : ");
		if (page->type == 8)
			ft_putstr("SMALL : ");
		if (page->type == 16)
			ft_putstr("LARGE : ");
		ft_putaddr(page);
		ft_putstr("\n");
		show_page(page);
		page = getprevpage(page);
	}
}
