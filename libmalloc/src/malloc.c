/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <avinas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:35:43 by avinas            #+#    #+#             */
/*   Updated: 2019/09/10 18:12:59 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/libmalloc.h"
#include "../include/page_manager.h"
#include "../include/allocator.h"

void	*malloc(size_t size)
{
	void	*ret;
	t_page	*page;

	ret = NULL;
	size = ALIGN16(size);
	if ((page = searchfreepage(size)) != NULL)
	{
		return (alloc(page, size));
	}
	createpage(size);
	if ((page = searchfreepage(size)) != NULL)
	{
		return (alloc(page, size));
	}
	return (ret);
}
