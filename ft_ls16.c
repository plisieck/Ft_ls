/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls16.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 14:59:54 by plisieck          #+#    #+#             */
/*   Updated: 2015/01/13 15:05:33 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		check_max_size(char **str, int *k, char *files)
{
	int			i;
	int			nb;
	int			ret;
	struct stat type;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (*k == -1)
			*k = 0;
		lstat(ft_strjoin(files, str[i]), &type);
		nb = ft_strlen(ft_itoa(type.st_size));
		if (nb > ret)
			ret = nb;
		i++;
		*k += (type.st_blocks);
	}
	return (ret);
}

int		check_max_major(char **str, char *files)
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
			nb = ft_strlen(ft_itoa(type.st_rdev >> 24));
			if (nb > ret)
				ret = nb;
		}
		i++;
	}
	return (ret);
}

char	*put_group_rights(struct stat type)
{
	char *str;

	if (((type.st_mode & S_IRWXO) == S_IRWXO)
	&& ((type.st_mode & S_ISGID) == (S_ISGID)))
		str = ft_strdup("rws");
	else if ((type.st_mode & S_IRWXG) == S_IRWXG &&
			(type.st_mode & S_ISGID) != S_ISGID)
		str = ft_strdup("rwx");
	else
	{
		str = (type.st_mode & S_IRGRP) == S_IRGRP ? "r" : "-";
		str = (type.st_mode & S_IWGRP) == S_IWGRP ? ft_strjoin
		(str, "w") : ft_strjoin(str, "-");
		if ((type.st_mode & S_IXGRP) == S_IXGRP &&
				(type.st_mode & S_ISGID) == S_ISGID)
			str = ft_strjoin(str, "s");
		else if ((type.st_mode & S_IXGRP) == S_IXGRP &&
				(S_ISGID & type.st_mode & S_ISGID) != S_ISGID)
			str = ft_strjoin(str, "x");
		else
			str = ((S_ISGID & type.st_mode) ? ft_strjoin
			(str, "S") : ft_strjoin(str, "-"));
	}
	return (str);
}

char	*put_others_rights(struct stat type)
{
	char *str;

	if (((type.st_mode & S_IRWXO) == S_IRWXO) &&
	((type.st_mode & S_ISVTX) == (S_ISVTX)))
		str = ft_strdup("rwt");
	else if ((type.st_mode & S_IRWXO) == S_IRWXO)
		str = ft_strdup("rwx");
	else
	{
		str = (type.st_mode & S_IROTH) == S_IROTH ? "r" : "-";
		if ((type.st_mode & S_IWOTH) == S_IWOTH)
			str = ft_strjoin(str, "w");
		else
			str = ft_strjoin(str, "-");
		if (((S_ISVTX & type.st_mode))
		&& ((type.st_mode & S_IXOTH) == (S_IXOTH)))
			str = ft_strjoin(str, "t");
		else if ((type.st_mode & S_IXOTH) == S_IXOTH)
			str = ft_strjoin(str, "x");
		else
			str = ((S_ISVTX & type.st_mode) ? ft_strjoin(str, "T")
			: ft_strjoin(str, "-"));
	}
	return (str);
}

char	*put_rights(struct stat type)
{
	char *str;
	char *str2;

	str2 = put_type(type);
	str = ft_strjoin(str2, put_user_rights(type));
	str = ft_strjoin(str, put_group_rights(type));
	str = ft_strjoin(str, put_others_rights(type));
	str = ft_strjoin(str, "  ");
	return (str);
}
