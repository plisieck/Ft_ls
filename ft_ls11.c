/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls11.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 15:26:17 by plisieck          #+#    #+#             */
/*   Updated: 2015/01/17 17:50:39 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	***third_check_readdir(int *i_j, char ***tab, struct dirent *lecture)
{
	if (lecture->d_name[0] != '.')
	{
		tab[i_j[0]][i_j[1]] = ft_strdup(lecture->d_name);
		tab[i_j[0]][i_j[1]][ft_strlen(lecture->d_name)] = '\0';
		i_j[1]++;
	}
	return (tab);
}

char	***second_check_readdir(int *i_j, char ***tab, int *opt, DIR **dir)
{
	struct dirent *lecture;

	while ((lecture = readdir(dir[i_j[0]])))
	{
		if (opt[2] || opt[7])
		{
			if (opt[7] && (ft_strcmp(lecture->d_name, ".")
						&& ft_strcmp(lecture->d_name, "..")))
			{
				tab[i_j[0]][i_j[1]] = ft_strdup(lecture->d_name);
				i_j[1]++;
			}
			else if (!opt[7] || opt[2])
			{
				tab[i_j[0]][i_j[1]] = ft_strdup(lecture->d_name);
				i_j[1]++;
			}
		}
		else
			tab = third_check_readdir(i_j, tab, lecture);
	}
	return (tab);
}

char	***first_check_readdir(DIR **dir, char **files, int *opt, char ***tab)
{
	int				i_j[2];
	struct dirent	*lecture;

	i_j[0] = 0;
	while (dir[i_j[0]])
	{
		i_j[1] = 0;
		while ((lecture = readdir(dir[i_j[0]])))
			i_j[1]++;
		tab[i_j[0]] = (char **)malloc(sizeof(char *) * i_j[1] + 1);
		i_j[1] = 0;
		if (opendir(files[i_j[0]]))
			dir[i_j[0]] = opendir(files[i_j[0]]);
		tab = second_check_readdir(i_j, tab, opt, dir);
		if (!opt[14])
			ft_sort_ascii(tab[i_j[0]]);
		tab[i_j[0]][i_j[1]] = '\0';
		i_j[0]++;
	}
	tab[i_j[0]] = '\0';
	return (tab);
}

char	***check_readdir(char **files, int *opt)
{
	int				i;
	int				j;
	int				k;
	DIR				**dir;
	char			***tab;

	i = 0;
	j = 0;
	while (files[i])
		i++;
	tab = (char ***)malloc(sizeof(char **) * i + 1);
	dir = (DIR **)malloc(sizeof(DIR *) * i + 1);
	check_errors(files);
	k = check_simple_files(files, opt);
	if (opt[8])
		return (NULL);
	split_check_readdir(files, dir, i, j);
	if (k == 1 && dir[0] != NULL)
		ft_putchar('\n');
	tab = first_check_readdir(dir, files, opt, tab);
	return (tab);
}

int		second_split_for_big_r(char *params, int multi_dir, int *opt)
{
	DIR				*dir;
	char			*temp3;
	char			*temp2;
	struct dirent	*lecture;
	int				i;

	dir = opendir(params);
	if (!dir)
	{
		temp3 = ft_strrchr(params, '/');
		temp2 = ft_strjoin(temp3++, ": ");
		temp2 = ft_strjoin("ft_ls: ", temp3);
		temp2 = ft_strjoin(temp2, ": ");
		ft_putendl_fd(ft_strjoin(temp2, strerror(errno)), 2);
		return (-1);
	}
	if (multi_dir == 1 && params[0] != '.')
		ft_putendl(ft_strjoin(params, ":"));
	i = 0;
	while ((lecture = readdir(dir)))
		if (lecture->d_name[0] != '.' || opt[2])
			i++;
	closedir(dir);
	free(lecture);
	return (i);
}
