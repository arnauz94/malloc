/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <avinas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:26:32 by avinas            #+#    #+#             */
/*   Updated: 2019/09/09 11:50:26 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libmalloc/libft/libft.h"
#include "../libmalloc/include/libmalloc.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;
	char	*total;
	char	*tmp;

	show_alloc_mem();
	total = ft_strnew(1);
	fd = open("../srcs/main.c", O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		tmp = ft_strjoin(total, line);
		ft_strdel(&total);
		total = tmp;
		total = ft_strjoin(total, "\n");
		ft_strdel(&tmp);
		ft_strdel(&line);
	}
	ft_putstr(total);
	show_alloc_mem();
	ft_strdel(&total);
	close(fd);
	fd = 0;
	ft_putstr("\n---------------------\n");
	show_alloc_mem();
}
