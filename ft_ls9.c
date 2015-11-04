/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls9.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 22:03:40 by plisieck          #+#    #+#             */
/*   Updated: 2015/01/18 12:52:45 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	checks_for_recursive(char **params, int *opt)
{
	DIR **dir;
	int multi_dir;
	int	i;
	int	k;

	i = 0;
	multi_dir = 0;
	while (params[i])
		i++;
	if (i > 1)
		multi_dir = 1;
	dir = malloc(sizeof(DIR) * i + 1);
	k = check_errors(params);
	if (k)
		return ;
	k = check_simple_files(params, opt);
	i = split_for_check_recursive(params, dir);
	if (k == 1 && dir[0] != NULL)
		ft_putchar('\n');
	split_for_recurssive(params, i, opt, multi_dir);
}

void	treat_option_recursiv(char *params, int *opt, int multi_dir)
{
	DIR		*dir;
	char	**tab;
	int		i;
	int		j;

	j = 0;
	if (opt[8] || first_split_for_big_r(params, opt))
		return ;
	i = second_split_for_big_r(params, multi_dir, opt);
	if (i == -1)
		return ;
	tab = third_split_for_big_r(i, opt, params, j);
	fifth_split_for_big_r(opt, tab, params);
	if ((dir = opendir(params)))
	{
		if (opt[3] == 0)
			seventh_for_big_r(opt, dir, params, multi_dir);
		else
			eighth_for_big_r(tab, params, opt, multi_dir);
		closedir(dir);
	}
	free(tab);
}

void	split_for_recurssive(char **params, int i, int *opt, int multi_dir)
{
	params = gestion_params(params);
	i = 0;
	while (params[i])
	{
		treat_option_recursiv(params[i], opt, multi_dir);
		if (opendir(params[i + 1]))
			ft_putchar('\n');
		i++;
	}
}

void	eighth_for_big_r(char **tab, char *params, int *opt, int multi_dir)
{
	int			i;
	char		*temp;
	struct stat type;

	i = 0;
	while (tab[i])
	{
		if (ft_strcmp(params, "/"))
			temp = ft_strjoin(params, "/");
		else
			temp = ft_strdup(params);
		temp = ft_strjoin(temp, tab[i]);
		lstat(temp, &type);
		if (S_ISDIR(type.st_mode) && ft_strcmp(tab[i], ".")
				&& ft_strcmp(tab[i], ".."))
		{
			if (tab[i][0] != '.' || opt[2])
			{
				ft_putchar('\n');
				ft_putendl(ft_strjoin(temp, ":"));
			}
			treat_option_recursiv(temp, opt, multi_dir);
		}
		i++;
	}
}

void	seventh_for_big_r(int *opt, DIR *dir, char *params, int multi_dir)
{
	struct dirent	*lecture;
	char			**tab4;
	int				x;

	x = 0;
	tab4 = (char **)malloc(sizeof(char *) * 100000000);
	while ((lecture = readdir(dir)))
	{
		if (ft_strcmp(lecture->d_name, ".") && ft_strcmp(lecture->d_name, ".."))
		{
			if (ft_strcmp(params, "/"))
				tab4[x] = ft_strjoin(params, "/");
			else
				tab4[x] = ft_strdup(params);
			tab4[x] = ft_strjoin(tab4[x], lecture->d_name);
			x++;
		}
	}
	tab4[x] = '\0';
	if (!opt[14])
		ft_sort_ascii(tab4);
	another_for_big_r(tab4, opt, multi_dir);
	free(lecture);
	free(tab4);
}
