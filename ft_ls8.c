/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 20:24:37 by plisieck          #+#    #+#             */
/*   Updated: 2015/01/11 20:47:50 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		check_simple_files(char **files, int *opt)
{
	int	i;
	int	j;
	int	k;
	DIR **dir;

	dir = split_simple_files_four(files);
	i = 0;
	j = 0;
	k = 0;
	split_simple_files_three(opt, files);
	while (files[i])
	{
		dir[j] = opendir(files[i]);
		if (!dir[j])
			split_simple_files(files, opt, i, &k);
		else
		{
			if (opt[8])
				split_simple_files_two(files, opt, i);
			closedir(dir[j]);
		}
		i++;
		j++;
	}
	return (k);
}

void	split_check_readdir(char **files, DIR **dir, int i, int j)
{
	i = 0;
	j = 0;
	while (files[i])
	{
		if ((dir[j] = opendir(files[i])))
			j++;
		i++;
	}
}

int		*split_long_format_file(char **reads, int *opt)
{
	int			i;
	struct stat type;
	int			*tab;

	i = 0;
	while (reads[i])
	{
		lstat(reads[i], &type);
		if ((type.st_mode & S_IFREG) == S_IFREG || opt[8])
			tab = check_max_lengths(reads, 1, "");
		i++;
	}
	return (tab);
}

void	print_long_for_file2(char *reads_i, int *opt, int *tab, char *print)
{
	struct stat type;

	lstat(reads_i, &type);
	print = put_attr(reads_i, type);
	print = put_number_of_links(type, print, tab[0]);
	if (!opt[6])
		print = put_owner_name(type, print, tab[1]);
	if (!opt[17])
		print = put_group_name(type, print, tab[2]);
	print = put_size(type, print, tab);
	if (opt[10])
		print = put_date_of_last_access(type, print, opt);
	if (opt[12] && (opt[4] || opt[0]) && !opt[13] && !opt[10])
		print = put_date_of_creation(type, print, opt);
	else if (opt[13])
		print = put_date_of_data(type, print, opt);
	else if (!opt[10] && !opt[12])
		print = put_date_of_last_modification(type, print, opt);
	if (opt[9] && S_ISDIR(type.st_mode))
		print = ft_strjoin(print, ft_strjoin(reads_i, "/"));
	else
		print = ft_strjoin(print, reads_i);
	if (S_ISLNK(type.st_mode))
		print = put_pathname(reads_i, reads_i, print);
	ft_putendl(print);
}

void	print_long_format_for_file(char **reads, int *opt)
{
	int			i;
	int			*tab;
	char		*print;
	struct stat	type;

	tab = split_long_format_file(reads, opt);
	i = 0;
	while (reads[i])
	{
		lstat(reads[i], &type);
		print = ft_strnew(0);
		if ((type.st_mode & S_IFREG) == S_IFREG || opt[8])
			print_long_for_file2(reads[i], opt, tab, print);
		i++;
	}
}
