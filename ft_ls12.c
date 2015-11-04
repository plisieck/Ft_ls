/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls12.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 14:38:23 by plisieck          #+#    #+#             */
/*   Updated: 2015/01/13 14:58:51 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	split_tri_stat(char ***reads, char **files, int i, int j)
{
	int			k;
	char		*temp;
	char		*temp2;
	struct stat	time;
	struct stat	time2;

	k = 0;
	temp = ft_strjoin(files[i], "/");
	while (reads[i][k])
	{
		lstat(ft_strjoin(temp, reads[i][j]), &time);
		lstat(ft_strjoin(temp, reads[i][k]), &time2);
		if (time.st_mtime > time2.st_mtime ||
		((time.st_mtime == time2.st_mtime) &&
		ft_strcmp(reads[i][j], reads[i][k]) < 0))
		{
			temp2 = reads[i][j];
			reads[i][j] = reads[i][k];
			reads[i][k] = temp2;
		}
		k++;
	}
}

void	tri_stat(char ***reads, char **files)
{
	int			i;
	int			j;

	i = 0;
	while (reads[i])
	{
		j = 0;
		while (reads[i][j])
		{
			split_tri_stat(reads, files, i, j);
			j++;
		}
		i++;
	}
}

void	split_tri_stat_big_u(char ***reads, char **files, int i, int j)
{
	int			k;
	char		*temp;
	char		*temp2;
	struct stat	time;
	struct stat	time2;

	k = 0;
	temp = ft_strjoin(files[i], "/");
	while (reads[i][k])
	{
		lstat(ft_strjoin(temp, reads[i][j]), &time);
		lstat(ft_strjoin(temp, reads[i][k]), &time2);
		if (time.st_birthtime > time2.st_birthtime ||
		((time.st_birthtime == time2.st_birthtime)
		&& ft_strcmp(reads[i][j], reads[i][k]) < 0))
		{
			temp2 = reads[i][j];
			reads[i][j] = reads[i][k];
			reads[i][k] = temp2;
		}
		k++;
	}
}

void	tri_stat_big_u(char ***reads, char **files)
{
	int			i;
	int			j;

	i = 0;
	while (reads[i])
	{
		j = 0;
		while (reads[i][j])
		{
			split_tri_stat_big_u(reads, files, i, j);
			j++;
		}
		i++;
	}
}

void	split_tri_stat_c(char ***reads, char **files, int i, int j)
{
	int			k;
	char		*temp;
	char		*temp2;
	struct stat	time;
	struct stat	time2;

	k = 0;
	temp = ft_strjoin(files[i], "/");
	while (reads[i][k])
	{
		lstat(ft_strjoin(temp, reads[i][j]), &time);
		lstat(ft_strjoin(temp, reads[i][k]), &time2);
		if (time.st_ctime > time2.st_ctime ||
		((time.st_ctime == time2.st_ctime)
		&& ft_strcmp(reads[i][j], reads[i][k]) < 0))
		{
			temp2 = reads[i][j];
			reads[i][j] = reads[i][k];
			reads[i][k] = temp2;
		}
		k++;
	}
}
