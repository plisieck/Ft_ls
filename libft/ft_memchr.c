/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:19:45 by plisieck          #+#    #+#             */
/*   Updated: 2014/11/30 14:15:12 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	unsigned int		i;
	unsigned char		*str;

	str = (unsigned char*)s;
	i = 0;
	if (s && n > 0)
	{
		while (i < n)
		{
			if (str[i] == (unsigned char)c)
			{
				return (str + i);
			}
			i++;
		}
	}
	return (NULL);
}
