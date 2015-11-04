/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_of_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 13:23:33 by plisieck          #+#    #+#             */
/*   Updated: 2015/01/05 14:09:44 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nb_of_char(const char *str, char c)
{
	int	i;
	int	nb;
	int len;

	if (!str)
		return (0);
	i = 0;
	nb = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] == c)
		{
			nb++;
		}
		i++;
	}
	return (nb);
}
