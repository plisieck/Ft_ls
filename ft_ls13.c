/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls13.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 14:46:02 by plisieck          #+#    #+#             */
/*   Updated: 2015/01/13 14:59:05 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	tri_stat_c(char ***reads, char **files)
{
	int			i;
	int			j;

	i = 0;
	while (reads[i])
	{
		j = 0;
		while (reads[i][j])
		{
			split_tri_stat_c(reads, files, i, j);
			j++;
		}
		i++;
	}
}

void	split_tri_stat_u(char ***reads, char **files, int i, int j)
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
		if (time.st_atime > time2.st_atime ||
		((time.st_atime == time2.st_atime)
		&& ft_strcmp(reads[i][j], reads[i][k]) < 0))
		{
			temp2 = reads[i][j];
			reads[i][j] = reads[i][k];
			reads[i][k] = temp2;
		}
		k++;
	}
}

void	tri_stat_u(char ***reads, char **files)
{
	int			i;
	int			j;

	i = 0;
	while (reads[i])
	{
		j = 0;
		while (reads[i][j])
		{
			split_tri_stat_u(reads, files, i, j);
			j++;
		}
		i++;
	}
}

void	split_tri_stat_s(char ***reads, char **files, int i, int j)
{
	int			k;
	char		*temp;
	char		*temp2;
	struct stat	size;
	struct stat	size2;

	k = 0;
	temp = ft_strjoin(files[i], "/");
	while (reads[i][k])
	{
		lstat(ft_strjoin(temp, reads[i][j]), &size);
		lstat(ft_strjoin(temp, reads[i][k]), &size2);
		if (size.st_size > size2.st_size || ((size.st_size == size2.st_size)
		&& ft_strcmp(reads[i][j], reads[i][k]) < 0))
		{
			temp2 = reads[i][j];
			reads[i][j] = reads[i][k];
			reads[i][k] = temp2;
		}
		k++;
	}
}

void	tri_stat_s(char ***reads, char **files)
{
	int			i;
	int			j;

	i = 0;
	while (reads[i])
	{
		j = 0;
		while (reads[i][j])
		{
			split_tri_stat_s(reads, files, i, j);
			j++;
		}
		i++;
	}
}
