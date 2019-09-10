/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <avinas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 12:51:11 by avinas            #+#    #+#             */
/*   Updated: 2019/08/20 15:51:51 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCATOR_H
# define ALLOCATOR_H

# include "page_manager.h"
# include "../libft/libft.h"

void	*alloc(t_page *page, size_t size);
void	*first_alloc(t_page *page, size_t size);

#endif
