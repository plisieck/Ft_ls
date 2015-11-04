/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls19.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 11:27:37 by plisieck          #+#    #+#             */
/*   Updated: 2015/01/18 12:54:06 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**gestion_params(char **params)
{
	int		i;
	int		j;
	int		k;
	char	**str;

	j = 0;
	k = split_gestion_params(params);
	str = (char **)malloc(sizeof(char *) * k + 1);
	i = 0;
	while (params[i])
	{
		if (opendir(params[i]))
		{
			str[j] = params[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

int		another_split_for_check_errors(char **files, int i, int k)
{
	char *str;

	if (ft_strlen(files[i]) > 0)
		str = ft_strjoin(files[i], ": ");
	else
	{
		str = ft_strjoin("fts_open", ": ");
		k = 1;
	}
	str = ft_strjoin("ft_ls: ", str);
	ft_putendl_fd(ft_strjoin(str, strerror(errno)), 2);
	return (k);
}

int		split_for_check_recursive(char **params, DIR **dir)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (params[i])
	{
		if ((dir[j] = opendir(params[i])))
			j++;
		i++;
	}
	return (i);
}
