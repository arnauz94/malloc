/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorielle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 00:05:02 by avinas            #+#    #+#             */
/*   Updated: 2017/11/20 00:24:10 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long	ft_factorielle(unsigned short nombre)
{
	if (nombre == 0)
		return (1);
	if (nombre > 20)
		return (0);
	else
		return (nombre * ft_factorielle(nombre - 1));
}
