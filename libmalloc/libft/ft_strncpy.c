/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 11:05:08 by avinas            #+#    #+#             */
/*   Updated: 2017/12/20 13:43:42 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int cpt;

	cpt = -1;
	while (++cpt < n && src[cpt] != '\0')
		dest[cpt] = src[cpt];
	while (cpt < n)
	{
		dest[cpt] = '\0';
		cpt++;
	}
	return (dest);
}
