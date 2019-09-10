/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <avinas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 16:07:11 by avinas            #+#    #+#             */
/*   Updated: 2019/09/10 18:13:05 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libmalloc.h"
#include "../include/page_manager.h"

void	*calloc(size_t nmemb, size_t size)
{
	void *new;

	new = malloc(nmemb * size);
	ft_memset(new, 0, ALIGN16(nmemb * size));
	return (new);
}
