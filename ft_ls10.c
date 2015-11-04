/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls10.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 22:10:58 by plisieck          #+#    #+#             */
/*   Updated: 2015/01/15 12:35:58 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sixth_for_big_r(int *opt, char ***tab3, char **params3, char **tab)
{
	int	i;

	i = 0;
	if (opt[3])
		ft_revtab(tab);
	if (opt[4] && !opt[12] && !opt[10] && !opt[14])
		tri_stat(tab3, params3);
	if (opt[4] && opt[12] && !opt[10] && !opt[14])
		tri_stat_big_u(tab3, params3);
	if (opt[4] && opt[13] && !opt[14])
		tri_stat_c(tab3, params3);
	if (opt[4] && opt[10] && !opt[12])
		tri_stat_u(tab3, params3);
	if (opt[11] && !opt[14])
		tri_stat_s(tab3, params3);
	if (opt[0] == 0)
	{
		while (tab[i])
		{
			ft_putendl(tab[i]);
			i++;
		}
	}
	else
		fourth_split_for_big_r(params3[0], opt, tab);
}

void	fifth_split_for_big_r(int *opt, char **tab, char *params)
{
	int		i;
	char	***tab3;
	char	**params3;

	i = 0;
	tab3 = malloc(sizeof(char ***) * i + 1);
	tab3[0] = tab;
	tab3[1] = '\0';
	params3 = malloc(sizeof(char **) * i + 1);
	params3[0] = params;
	params3[1] = '\0';
	sixth_for_big_r(opt, tab3, params3, tab);
	free(params3);
	free(tab3);
}

char	**third_split_for_big_r(int i, int *opt, char *params, int j)
{
	char			**tab;
	struct stat		type;
	struct dirent	*lecture;
	DIR				*dir;

	tab = (char **)malloc(sizeof(char *) * i + 1);
	tab[i] = '\0';
	dir = opendir(params);
	while ((lecture = readdir(dir)))
	{
		if (lecture->d_name[0] != '.' || opt[2])
		{
			lstat(lecture->d_name, &type);
			if (opt[9] && S_ISDIR(type.st_mode))
				tab[j] = ft_strjoin(ft_strdup(lecture->d_name), "/");
			else
				tab[j] = ft_strdup(lecture->d_name);
			j++;
		}
	}
	if (!opt[14])
		ft_sort_ascii(tab);
	closedir(dir);
	return (tab);
}

void	fourth_split_for_big_r(char *params, int *opt, char **tab)
{
	char	***tab2;
	char	**params2;

	tab2 = (char ***)malloc(sizeof(char **) * 2);
	params2 = (char **)malloc(sizeof(char *) * 2);
	tab2[0] = tab;
	tab2[1] = '\0';
	params2[0] = params;
	params2[1] = '\0';
	print_long_format(tab2, params2, opt);
	free(params2);
	free(tab2);
}

int		first_split_for_big_r(char *params, int *opt)
{
	char *temp;

	temp = ft_strnew(0);
	temp = ft_strrchr(params, '/');
	if (temp)
	{
		if (params[ft_strlen(params) - 1] != '/')
			temp = ft_strsub(temp, 1, ft_strlen(temp) - 1);
		if (temp[0] == '.' && !opt[2])
			return (1);
	}
	if (check_if_is_file(params) == 1)
		return (1);
	return (0);
}
