/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 12:49:54 by plisieck          #+#    #+#             */
/*   Updated: 2015/01/15 12:49:57 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*third_split_for_plg(struct stat type, char *print, int *tab, int *opt)
{
	print = put_number_of_links(type, print, tab[0]);
	if (!opt[6])
		print = put_owner_name(type, print, tab[1]);
	if (!opt[17])
		print = put_group_name(type, print, tab[2]);
	if (opt[6] && opt[17])
		print = ft_strjoin(print, "  ");
	print = put_size(type, print, tab);
	if (opt[10])
		print = put_date_of_last_access(type, print, opt);
	if (opt[12] && (opt[4] || opt[0]) && !opt[13] && !opt[10])
		print = put_date_of_creation(type, print, opt);
	if (opt[13])
		print = put_date_of_data(type, print, opt);
	else if (!opt[10] && !opt[12])
		print = put_date_of_last_modification(type, print, opt);
	return (print);
}

char	*fourth_split_for_plg(int *tab, char **files, int i)
{
	char		*temp;

	if (tab[6] != -1)
	{
		ft_putstr("total ");
		ft_putnbr(tab[6]);
		ft_putchar('\n');
	}
	temp = ft_strjoin(files[i], "/");
	return (temp);
}

void	split_for_plg(int *opt, char ***reads, int *tab, char **files)
{
	char		*print;
	struct stat	type;
	int			j;
	char		*temp;

	j = 0;
	temp = fourth_split_for_plg(tab, files, opt[19]);
	while (reads[opt[19]][j])
	{
		lstat(ft_strjoin(temp, reads[opt[19]][j]), &type);
		print = put_attr(ft_strjoin(temp, reads[opt[19]][j]), type);
		print = third_split_for_plg(type, print, tab, opt);
		if (opt[9] && S_ISDIR(type.st_mode))
			print = ft_strjoin(print, ft_strjoin(reads[opt[19]][j], "/"));
		else
			print = ft_strjoin(print, reads[opt[19]][j]);
		if (opt[18])
			print = second_split_for_plg(type, print);
		if (S_ISLNK(type.st_mode))
			print = put_pathname(temp, reads[opt[19]][j], print);
		ft_putendl(print);
		if (print)
			free(print);
		j++;
	}
}

void	print_long_format(char ***reads, char **files, int *opt)
{
	int			*tab;
	struct stat	type;
	int			*total;

	total = first_split_for_plg(reads);
	opt[19] = 0;
	while (reads[opt[19]])
	{
		tab = check_max_lengths(reads[opt[19]], 2, files[opt[19]]);
		lstat(files[opt[19]], &type);
		if (!S_ISLNK(type.st_mode))
			split_for_plg(opt, reads, tab, files);
		opt[19]++;
		if (reads[opt[19]])
			ft_putchar('\n');
	}
	free(total);
}

int		main(int argc, char **argv)
{
	int		opt[20];
	char	**params;
	char	***reads;
	int		k;

	params = check_argv(argc, argv);
	k = little_for_main(params);
	if (!split_for_main(opt, argv, argc, params))
		return (0);
	if (opt[1] == 1)
		checks_for_recursive(params, opt);
	else
	{
		if (opt[3])
			ft_revtab(params);
		reads = check_readdir(params, opt);
		if (reads == NULL)
			return (0);
		select_options(opt, reads, params, &k);
	}
	free(params);
	return (0);
}
