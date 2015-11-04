/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 12:50:16 by plisieck          #+#    #+#             */
/*   Updated: 2015/01/15 12:50:19 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	***split_for_simple_print(char ***tab, int l, int j, int *opt)
{
	struct stat type;

	while (tab[l][j])
	{
		if (opt[18])
			tab[l][j] = treat_option_big_f(tab[l][j], tab[l][j]);
		if (opt[9])
		{
			if (lstat(tab[l][j], &type) == 0)
				if (S_ISDIR(type.st_mode))
					tab[l][j] = ft_strjoin(tab[l][j], "/");
		}
		ft_putendl(tab[l][j]);
		j++;
	}
	return (tab);
}

void	simple_print(char ***tab, char **files, int *m, int *opt)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	l = 0;
	while (files[i] && l < *m)
	{
		j = 0;
		if (opendir(files[i]))
		{
			if (*m > 1)
				ft_putendl(ft_strjoin(files[i], ":"));
			tab = split_for_simple_print(tab, l, j, opt);
			if (tab[l + 1])
				ft_putchar('\n');
			l++;
		}
		i++;
	}
}

char	***treat_option_r(char ***original_tab)
{
	int	i;

	i = 0;
	while (original_tab[i])
	{
		ft_revtab(original_tab[i]);
		i++;
	}
	return (original_tab);
}

int		check_if_is_file(char *file)
{
	struct stat type;

	if (lstat(file, &type) == -1)
		return (0);
	if ((type.st_mode & S_IFREG) == S_IFREG)
		return (1);
	else
		return (0);
	return (-1);
}

void	select_options(int *opt, char ***readdir, char **files, int *k)
{
	if (opt[4] && !opt[12] && !opt[10] && !opt[14])
		tri_stat(readdir, files);
	if (opt[4] && opt[10] && !opt[12] && !opt[14])
		tri_stat_u(readdir, files);
	if (opt[4] && opt[12] && !opt[10] && !opt[14])
		tri_stat_big_u(readdir, files);
	if (opt[4] && opt[13] && !opt[14])
		tri_stat_c(readdir, files);
	if (opt[11] && !opt[14])
		tri_stat_s(readdir, files);
	if (opt[3] && !opt[14])
		readdir = treat_option_r(readdir);
	if (!opt[0])
		simple_print(readdir, files, k, opt);
	else if (opt[0])
	{
		print_long_format_for_file(files, opt);
		print_long_format(readdir, files, opt);
	}
}
