/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls14.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 14:50:06 by plisieck          #+#    #+#             */
/*   Updated: 2015/01/13 14:59:13 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		*first_split_for_plg(char ***reads)
{
	int	i;
	int *total;
	int	temp_total;

	i = 0;
	total = 0;
	while (reads[i] != NULL)
		i++;
	total = (int *)malloc(sizeof(int) * i);
	i = 0;
	while (reads[i])
	{
		temp_total = 0;
		total[i] = temp_total;
		i++;
	}
	return (total);
}

char	*second_split_for_plg(struct stat type, char *print)
{
	if (S_ISFIFO(type.st_mode))
		print = ft_strjoin(print, "|");
	if (S_ISDIR(type.st_mode))
		print = ft_strjoin(print, "/");
	if (S_ISLNK(type.st_mode))
		print = ft_strjoin(print, "@");
	if (S_ISSOCK(type.st_mode))
		print = ft_strjoin(print, "=");
	else if (!S_ISDIR(type.st_mode) &&
	!S_ISLNK(type.st_mode) &&
	(S_IXUSR & type.st_mode || S_IXGRP &
	type.st_mode || S_IXOTH & type.st_mode))
		print = ft_strjoin(print, "*");
	return (print);
}

char	*right_align(char *str, unsigned int max)
{
	while (ft_strlen(str) < max)
		str = ft_strjoin(" ", str);
	return (str);
}

char	*left_align(char *str, unsigned int max)
{
	while (ft_strlen(str) < max)
		str = ft_strjoin(str, " ");
	return (str);
}

int		check_max_nlink(char **str, char *files)
{
	int			i;
	int			nb;
	int			ret;
	struct stat type;

	i = 0;
	ret = 0;
	while (str[i])
	{
		lstat(ft_strjoin(files, str[i]), &type);
		nb = ft_strlen(ft_itoa(type.st_nlink));
		if (nb > ret)
			ret = nb;
		i++;
	}
	return (ret);
}
