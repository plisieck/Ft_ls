/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 16:07:25 by plisieck          #+#    #+#             */
/*   Updated: 2015/01/05 14:14:30 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_length(int n, size_t *len, int *diz)
{
	*len = 1;
	if (n >= 0)
	{
		*len = 0;
		n = -n;
	}
	*diz = 1;
	while (n / *diz < -9)
	{
		*diz = *diz * 10;
		*len = *len + 1;
	}
}

char		*ft_itoa(int n)
{
	size_t		len;
	int			diz;
	int			i;
	char		*str;

	ft_length(n, &len, &diz);
	str = ft_strnew(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		str[i] = '-';
		i++;
	}
	if (n > 0)
		n = -n;
	while (diz >= 1)
	{
		str[i] = -(n / diz % 10) + 48;
		diz = diz / 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}
