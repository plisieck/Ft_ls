/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:40:48 by plisieck          #+#    #+#             */
/*   Updated: 2015/01/05 14:51:30 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	size1;
	unsigned int	size2;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (-1);
	if (!s2)
		return (1);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if (n > size1)
		n = size1 + 1;
	if (n > size2)
		n = size2 + 1;
	return (ft_memcmp(s1, s2, n));
}
