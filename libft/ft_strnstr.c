/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 15:23:47 by plisieck          #+#    #+#             */
/*   Updated: 2015/01/04 18:50:20 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	char	c;
	char	str;
	size_t	len;

	i = 0;
	if ((c = *s2++) != '\0')
	{
		len = ft_strlen(s2);
		while (!i || ft_strncmp(s1, s2, len) != 0)
		{
			i = 1;
			if ((str = *s1++) == '\0' || n-- < 1)
				return (NULL);
			while (str != c)
			{
				if ((str = *s1++) == '\0' || n-- < 1)
					return (NULL);
			}
			if (len > n)
				return (NULL);
		}
		s1--;
	}
	return ((char *)s1);
}
