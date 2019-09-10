/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_type.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <avinas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:55:36 by avinas            #+#    #+#             */
/*   Updated: 2019/08/20 17:54:30 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_TYPE_H
# define UTILS_TYPE_H
# include <stdlib.h>
# include <unistd.h>
# define TINY (size_t)(getpagesize() / 4)
# define SMALL (size_t)(getpagesize() / 2)

int	get_mypage_size(size_t size);
int	get_type(size_t size);

#endif
