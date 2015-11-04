/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 15:23:19 by plisieck          #+#    #+#             */
/*   Updated: 2014/11/15 15:23:22 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*str = NULL;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			str = s + i;
		}
		i++;
	}
	if (c == '\0' && s[i] == '\0')
		return ((char*)&s[i]);
	return ((char*)str);
}
