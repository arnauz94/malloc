/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmalloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <avinas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:29:11 by avinas            #+#    #+#             */
/*   Updated: 2019/08/21 15:54:42 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMALLOC_H
# define LIBMALLOC_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

void	free(void *ptr);
void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);
void	show_alloc_mem();
void	*calloc(size_t nmemb, size_t size);

#endif
