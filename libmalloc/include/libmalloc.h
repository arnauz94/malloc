/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmalloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <avinas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:29:11 by avinas            #+#    #+#             */
/*   Updated: 2019/09/12 16:47:15 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMALLOC_H
# define LIBMALLOC_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

static	pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;

void	free(void *ptr);
void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);
size_t	malloc_size(const void *ptr);
size_t	malloc_good_size(size_t size);
void	show_alloc_mem();
void	*calloc(size_t nmemb, size_t size);

#endif
