/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 20:10:09 by plisieck          #+#    #+#             */
/*   Updated: 2014/11/15 13:02:48 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	if (!s2[0])
		return ((char *)&s1[i]);
	while (s1[i] != '\0')
	{
		k = i;
		while (s1[k] == s2[j])
		{
			k++;
			j++;
			if (s2[j] == '\0')
				return ((char *)&s1[i]);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
