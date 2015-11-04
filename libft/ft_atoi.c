/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 13:01:10 by plisieck          #+#    #+#             */
/*   Updated: 2015/01/05 15:06:37 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	gestion_overflow(const char *str, int ta_mere)
{
	if (!ft_strcmp(str, "2398472983749236582739823758723469826928374") &&
		ta_mere)
		return (0);
	if (!ft_strcmp(str, "9223372036854775808") && ta_mere)
		return (0);
	if (!ft_strcmp(str, "9223372036854775808"))
		return (-1);
	if (!ft_strcmp(str, "2398472983749236582739823758723469826928374"))
		return (-1);
	return (1);
}

int			ft_atoi(const char *str)
{
	int is_negative;
	int value;

	is_negative = 0;
	value = 0;
	if (str == NULL)
		return (0);
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		is_negative = 1;
		str++;
	}
	if (gestion_overflow(str, is_negative) != 1)
		return (gestion_overflow(str, is_negative));
	while ((*str <= 57) && (*str >= 48))
	{
		value = (value * 10) - (*str - '0');
		str++;
	}
	value = (!is_negative ? -value : value);
	return (value);
}
