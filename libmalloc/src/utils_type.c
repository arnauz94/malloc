/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <avinas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:07:55 by avinas            #+#    #+#             */
/*   Updated: 2019/08/20 16:02:41 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../include/utils_type.h"
#include "../include/page_manager.h"

int	get_mypage_size(size_t size)
{
	int page;

	page = getpagesize();
	if (size <= TINY)
		return (page * 27);
	if (size <= SMALL)
	{
		return (page * 52);
	}
	else
	{
		return ((((size) / page) + 1) * page) + sizeof(t_page) * 3;
	}
}

int	get_type(size_t size)
{
	int page;

	page = getpagesize();
	if (size <= TINY)
		return (4);
	if (size <= SMALL)
	{
		return (8);
	}
	else
	{
		return (16);
	}
}
