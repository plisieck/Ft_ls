/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:54:52 by plisieck          #+#    #+#             */
/*   Updated: 2014/11/10 15:15:27 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *str1;
	char *str2;

	if (dst < src)
		return (ft_memcpy(dst, src, len));
	if (dst > src)
	{
		if (len == 0 || dst == src)
			return (dst);
		str1 = (char *)dst;
		str2 = (char *)src;
		while (len--)
		{
			str1[len] = str2[len];
		}
		return (dst);
	}
	return (dst);
}
