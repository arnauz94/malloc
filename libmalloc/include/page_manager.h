/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page_manager.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <avinas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:53:51 by avinas            #+#    #+#             */
/*   Updated: 2019/08/20 15:55:16 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAGE_MANAGER_H
# define PAGE_MANAGER_H
# include <sys/mman.h>
# include <stdlib.h>
# include "libmalloc.h"

# define ALIGN16(x) (((((x) - 1)>> 4 ) << 4) + 16)

typedef struct		s_page
{
	int				type;
	void			*data;
	size_t			size;
	struct s_page	*next;
	struct s_page	*prev;
	int				isfree;
}					t_page;

t_page				*searchfreepage(size_t size);
void				*createpage(size_t size);
t_page				**getfirstpage();
t_page				*getnextpage(t_page *page);
t_page				*getprevpage(t_page *page);

#endif
