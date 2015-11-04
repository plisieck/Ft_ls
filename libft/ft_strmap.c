/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 15:17:37 by plisieck          #+#    #+#             */
/*   Updated: 2015/01/05 14:50:24 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*map;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	map = ft_strdup(s);
	if (!map)
		return (NULL);
	while (map[i] != '\0')
	{
		map[i] = f(map[i]);
		i++;
	}
	return (map);
}
