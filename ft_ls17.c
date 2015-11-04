/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls17.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 15:06:23 by plisieck          #+#    #+#             */
/*   Updated: 2015/01/13 15:06:53 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*put_attr(char *path, struct stat type)
{
	int		i;
	char	*str2;

	str2 = put_rights(type);
	i = listxattr(path, NULL, 1, XATTR_NOFOLLOW);
	if (acl_get_file(path, ACL_TYPE_EXTENDED))
		str2[10] = '+';
	if (i > 0)
		str2[10] = '@';
	return (str2);
}

char	*put_number_of_links(struct stat type, char *print, int max_nlink)
{
	char	*str;

	str = ft_strjoin(print, right_align(ft_itoa(type.st_nlink), max_nlink));
	str = ft_strjoin(str, " ");
	return (str);
}

char	*put_owner_name(struct stat type, char *print, int max_pwuid)
{
	char			*str;
	struct passwd	*getid;

	getid = getpwuid(type.st_uid);
	if (getid)
		str = ft_strjoin(print, left_align(getid->pw_name, max_pwuid));
	else
		str = ft_strjoin(print, left_align(ft_itoa(type.st_uid), max_pwuid));
	str = ft_strjoin(str, "  ");
	return (str);
}

char	*put_group_name(struct stat type, char *print, int max_gruid)
{
	char			*str;
	struct group	*getgrp;

	getgrp = getgrgid(type.st_gid);
	if (getgrp)
		str = ft_strjoin(print, left_align(getgrp->gr_name, max_gruid));
	else
		str = ft_strjoin(print, left_align(ft_itoa(type.st_gid), max_gruid));
	str = ft_strjoin(str, "  ");
	return (str);
}

char	*put_major(struct stat type, char *print, int max_major)
{
	char *str;

	str = ft_strjoin(print, " ");
	str = ft_strjoin(str, right_align(ft_itoa(type.st_rdev >> 24), max_major));
	str = ft_strjoin(str, ft_strdup(","));
	str = ft_strjoin(str, " ");
	return (str);
}
