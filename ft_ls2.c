/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 12:31:47 by plisieck          #+#    #+#             */
/*   Updated: 2015/01/15 12:50:07 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*put_date_of_data(struct stat type, char *print, int *opt)
{
	int		i;
	char	*str;
	char	*temp;
	char	*months;
	time_t	tloc;

	temp = ctime(&(type.st_ctime));
	i = type.st_ctime;
	tloc = 0;
	time(&tloc);
	if (i > tloc - ((365 / 2) * (86400)) && i < tloc + 60)
		temp = ft_strsub(temp, 4, 12);
	else
	{
		if (!opt[15])
		{
			months = ft_strsub(temp, 4, 7);
			temp = ft_strsub(temp, 19, 5);
			temp = ft_strjoin(months, temp);
		}
	}
	str = ft_strjoin(print, temp);
	str = ft_strjoin(str, " ");
	return (str);
}

char	*put_date_of_creation(struct stat type, char *print, int *opt)
{
	int		i;
	char	*str;
	char	*temp;
	char	*months;
	time_t	tloc;

	temp = ctime(&(type.st_birthtime));
	i = type.st_birthtime;
	tloc = 0;
	time(&tloc);
	if (i > tloc - ((365 / 2) * (86400)) && i < tloc + 60)
		temp = (!opt[15]) ? ft_strsub(temp, 4, 12)
		: ft_strsub(temp, 4, 20);
	else
	{
		months = ft_strsub(temp, 4, 7);
		temp = ft_strsub(temp, 19, 5);
		temp = ft_strjoin(months, temp);
	}
	str = ft_strjoin(print, temp);
	str = ft_strjoin(str, " ");
	return (str);
}

char	*put_date_of_last_modification(struct stat type, char *print, int *opt)
{
	int		i;
	char	*str;
	char	*temp;
	char	*months;
	time_t	tloc;

	temp = ctime(&(type.st_mtime));
	i = type.st_mtime;
	tloc = 0;
	time(&tloc);
	if (i > tloc - ((365 / 2) * (86400)) && i < tloc + 60)
		temp = (!opt[15]) ? ft_strsub(temp, 4, 12)
		: ft_strsub(temp, 4, 20);
	else
	{
		months = ft_strsub(temp, 4, 7);
		temp = ft_strsub(temp, 19, 5);
		temp = ft_strjoin(months, temp);
	}
	str = ft_strjoin(print, temp);
	str = ft_strjoin(str, " ");
	return (str);
}

char	*put_date_of_last_access(struct stat type, char *print, int *opt)
{
	int		i;
	char	*str;
	char	*temp;
	char	*months;
	time_t	tloc;

	temp = ctime(&(type.st_atime));
	i = type.st_atime;
	tloc = 0;
	time(&tloc);
	if (i > tloc - ((365 / 2) * (86400)) && i < tloc + 60)
		temp = (!opt[15]) ? ft_strsub(temp, 4, 12)
		: ft_strsub(temp, 4, 20);
	else
	{
		months = ft_strsub(temp, 4, 7);
		temp = ft_strsub(temp, 19, 5);
		temp = ft_strjoin(months, temp);
	}
	str = ft_strjoin(print, temp);
	str = ft_strjoin(str, " ");
	return (str);
}

char	*put_pathname(char *path, char *name, char *print)
{
	char	*str;
	char	*temp;
	int		i;

	temp = ft_strnew(255);
	if (!ft_strcmp(path, name))
		i = readlink(path, temp, 255);
	else
		i = readlink(ft_strjoin(path, name), temp, 255);
	temp[i] = '\0';
	str = ft_strjoin(print, " -> ");
	str = ft_strjoin(str, temp);
	return (str);
}
