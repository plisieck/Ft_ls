/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 20:20:47 by plisieck          #+#    #+#             */
/*   Updated: 2015/01/12 12:33:21 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	check_options(int *tab, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < 20)
	{
		tab[i] = 0;
		i++;
	}
	i = 1;
	while ((argv[i] && argv[i][0] == '-') && (argv[i][1]))
	{
		j = 1;
		split_check_option(tab, argv, i, j);
		if (tab[16])
			break ;
		i++;
	}
}

void	split_simple_files(char **files, int *opt, int i, int *k)
{
	if (check_if_is_file(files[i]) == 1 && opt[0] == 0)
	{
		*k = 1;
		ft_putendl(files[i]);
	}
}

void	split_simple_files_two(char **files, int *opt, int i)
{
	if (opt[0])
		print_long_format_for_file(files, opt);
	else
		ft_putendl(files[i]);
}

void	split_simple_files_three(int *opt, char **files)
{
	if (opt[3])
		ft_revtab(files);
}

DIR		**split_simple_files_four(char **files)
{
	int	i;
	DIR **dir;

	i = 0;
	while (files[i])
		i++;
	dir = (DIR **)malloc(sizeof(DIR *) * i + 1);
	return (dir);
}
