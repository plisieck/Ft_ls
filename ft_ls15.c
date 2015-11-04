/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls15.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 14:54:52 by plisieck          #+#    #+#             */
/*   Updated: 2015/01/13 15:03:37 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		check_max_pwuid(char **str, char *files)
{
	int				i;
	int				nb;
	int				ret;
	struct stat		type;
	struct passwd	*getid;

	i = 0;
	ret = 0;
	while (str[i])
	{
		lstat(ft_strjoin(files, str[i]), &type);
		getid = getpwuid(type.st_uid);
		if (getid)
			nb = ft_strlen(getid->pw_name);
		else
			nb = ft_strlen(ft_itoa(type.st_uid));
		if (nb > ret)
			ret = nb;
		i++;
	}
	return (ret);
}

int		check_max_gruid(char **str, char *files)
{
	int				i;
	int				nb;
	int				ret;
	struct stat		type;
	struct group	*getgrp;

	i = 0;
	ret = 0;
	while (str[i])
	{
		lstat(ft_strjoin(files, str[i]), &type);
		getgrp = getgrgid(type.st_gid);
		if (getgrp)
			nb = ft_strlen(getgrp->gr_name);
		else
			nb = ft_strlen(ft_itoa(type.st_gid));
		if (nb > ret)
			ret = nb;
		i++;
	}
	return (ret);
}

int		check_max_minor(char **str, char *files)
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
		if (S_ISCHR(type.st_mode) || S_ISBLK(type.st_mode))
		{
			nb = ft_strlen(ft_itoa(type.st_rdev & 255));
			if (nb > ret)
				ret = nb;
		}
		i++;
	}
	return (ret);
}

char	*put_type(struct stat type)
{
	char *str;

	if ((type.st_mode & S_IFDIR) == S_IFDIR)
		str = ft_strdup("d");
	if ((type.st_mode & S_IFCHR) == S_IFCHR)
		str = ft_strdup("c");
	if ((type.st_mode & S_IFBLK) == S_IFBLK)
		str = ft_strdup("b");
	if ((type.st_mode & S_IFIFO) == S_IFIFO)
		str = ft_strdup("p");
	if ((type.st_mode & S_IFREG) == S_IFREG)
		str = ft_strdup("-");
	if ((type.st_mode & S_IFSOCK) == S_IFSOCK)
		str = ft_strdup("s");
	if ((type.st_mode & S_IFLNK) == S_IFLNK)
		str = ft_strdup("l");
	return (str);
}

char	*put_user_rights(struct stat type)
{
	char *str;

	if (((type.st_mode & S_IRWXO) == S_IRWXO)
	&& ((type.st_mode & S_ISUID) == (S_ISUID)))
		str = ft_strdup("rws");
	else if ((type.st_mode & S_IRWXU) == S_IRWXU &&
			(type.st_mode & S_ISUID) != S_ISUID)
		str = ft_strdup("rwx");
	else
	{
		str = (type.st_mode & S_IRUSR) == S_IRUSR ? "r" : "-";
		str = (type.st_mode & S_IWUSR) == S_IWUSR ? ft_strjoin
		(str, "w") : ft_strjoin(str, "-");
		if ((type.st_mode & S_IXUSR) == S_IXUSR &&
				(type.st_mode & S_ISUID) == S_ISUID)
			str = ft_strjoin(str, "s");
		else if ((type.st_mode & S_IXUSR) == S_IXUSR &&
				(type.st_mode & S_ISUID) != S_ISUID)
			str = ft_strjoin(str, "x");
		else
			str = (type.st_mode & S_ISUID) == S_ISUID ? ft_strjoin
			(str, "S") : ft_strjoin(str, "-");
	}
	return (str);
}
