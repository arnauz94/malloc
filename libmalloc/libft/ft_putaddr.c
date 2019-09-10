/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <avinas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 17:25:01 by avinas            #+#    #+#             */
/*   Updated: 2019/08/21 16:39:13 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putaddr_fd(void *str, int fd)
{
	long int			div;
	char				temp;
	unsigned long int	n;

	n = (unsigned long int)str;
	div = 16;
	write(fd, "0x", 2);
	while (n / div >= 16)
		div *= 16;
	while (div > 0)
	{
		temp = '0' + n / div;
		if (temp > '9')
		{
			temp += 7;
			write(fd, &temp, 1);
		}
		else
			write(fd, &temp, 1);
		n %= div;
		div /= 16;
	}
}

void	ft_putaddr(void *str)
{
	ft_putaddr_fd(str, 1);
}
