/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:26:26 by plisieck          #+#    #+#             */
/*   Updated: 2015/01/05 14:45:16 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (NULL);
	str1 = (char *)src;
	str2 = (char *)dst;
	if (n != 0)
	{
		while (i < n)
		{
			str2[i] = str1[i];
			if (str1[i] == c)
				return (str2 + i + 1);
			i++;
		}
	}
	return (NULL);
}
