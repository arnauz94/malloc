/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reallocf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <avinas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:42:06 by avinas            #+#    #+#             */
/*   Updated: 2019/09/12 16:57:49 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libmalloc.h"
#include "../include/page_manager.h"

void		*reallocf(void *ptr, size_t size)
{
	void	*new;

	if (!(new = realloc(ptr, size)))
		free(ptr);
	return (new);
}
