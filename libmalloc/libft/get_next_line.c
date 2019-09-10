/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <avinas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:23:23 by avinas            #+#    #+#             */
/*   Updated: 2019/08/11 17:14:54 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		my_realloc(char **rest, char *buf)
{
	char	*tmp;

	if (rest && *rest)
	{
		tmp = ft_strjoin(*rest, buf);
		ft_strdel(rest);
		*rest = tmp;
	}
	else
	{
		*rest = ft_strdup(buf);
	}
}

static char	*get_next(char *rest)
{
	int		cpt;
	int		i;
	char	*ret;

	cpt = 0;
	i = 0;
	while (rest[cpt] != '\n' && rest[cpt])
	{
		cpt++;
	}
	ret = ft_strnew(cpt);
	if (ret == NULL)
		return (NULL);
	ft_strncpy(ret, rest, cpt);
	return (ret);
}

static int	ft_strlenmod(char *rest)
{
	char	*tmp;
	int		cpt;

	tmp = rest;
	cpt = 0;
	while (*tmp != '\n' && *tmp)
	{
		tmp++;
		cpt++;
	}
	if (!*tmp)
		return (-1);
	return (cpt);
}

static void	removefirst(char **rest)
{
	int		cpt;
	char	*tmp;

	cpt = ft_strlenmod(*rest);
	if (cpt == -1)
	{
		*rest = NULL;
		return ;
	}
	cpt++;
	tmp = ft_strsub(*rest, cpt, ft_strlen(*rest));
	ft_strdel(rest);
	*rest = tmp;
}

int			get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				count;
	static char		*rest = NULL;

	while ((count = read(fd, buf, BUFF_SIZE)) != 0)
	{
		if (count < 0)
			return (-1);
		buf[count] = '\0';
		my_realloc(&rest, buf);
		if (rest == NULL)
			return (-1);
		if ((ft_strchr(rest, '\n')) != NULL)
			break ;
	}
	if (rest)
	{
		if (!ft_strcmp(rest, ""))
			return (0);
		*line = get_next(rest);
		removefirst(&rest);
		return (1);
	}
	(rest) ? ft_strdel(&rest) : 0;
	return (0);
}
