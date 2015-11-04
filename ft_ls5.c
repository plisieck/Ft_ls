/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 17:38:39 by plisieck          #+#    #+#             */
/*   Updated: 2015/01/18 13:58:20 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		split_for_check_errors(char **files, DIR **dir)
{
	int			i;
	int			j;
	int			k;
	struct stat	type;

	i = 0;
	j = 0;
	k = 0;
	while (files[i])
	{
		dir[j] = opendir(files[i]);
		if (!dir[j])
		{
			if ((lstat(files[i], &type) == -1) || (!S_ISREG(type.st_mode)
						&& (!S_ISLNK(type.st_mode))))
				if (another_split_for_check_errors(files, i, k) == 1)
					return (1);
		}
		else
			closedir(dir[j]);
		i++;
		j++;
	}
	return (k);
}

int		check_errors(char **files)
{
	int		i;
	DIR		**dir;
	int		k;

	i = 0;
	while (files[i])
		i++;
	dir = (DIR **)malloc(sizeof(DIR *) * i + 1);
	k = split_for_check_errors(files, dir);
	free(dir);
	return (k);
}

int		*split_check_max_lengths(char **reads, char *files, int *tab, int k)
{
	files = ft_strjoin(files, "/");
	tab[0] = check_max_nlink(reads, files);
	tab[1] = check_max_pwuid(reads, files);
	tab[2] = check_max_gruid(reads, files);
	tab[3] = check_max_size(reads, &k, files);
	tab[4] = check_max_major(reads, files);
	tab[5] = check_max_minor(reads, files);
	tab[6] = k;
	return (tab);
}

int		*check_max_lengths(char **reads, int z, char *files)
{
	int	*tab;
	int	k;
	int	i;

	i = 0;
	tab = (int*)malloc(sizeof(int) * 7);
	while (i < 7)
	{
		tab[i] = 0;
		i++;
	}
	k = -1;
	if (z == 1)
	{
		tab[0] = check_max_nlink(reads, "");
		tab[1] = check_max_pwuid(reads, "");
		tab[2] = check_max_gruid(reads, "");
		tab[3] = check_max_size(reads, &k, "");
	}
	if (z == 2)
		tab = split_check_max_lengths(reads, files, tab, k);
	return (tab);
}

int		split_for_main(int *opt, char **argv, int argc, char **params)
{
	if (argc >= 1)
	{
		check_options(opt, argv);
		if (!opt[14])
			ft_sort_ascii(params);
		if (opt[5] == -1)
			return (0);
		if (opt[3] == 1 && opt[4] == 0)
			ft_revtab(params);
	}
	return (1);
}
