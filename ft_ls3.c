/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 15:03:20 by plisieck          #+#    #+#             */
/*   Updated: 2015/01/17 18:15:06 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_option_error(char c)
{
	char	*str;

	str = ft_strdup("ft_ls: illegal option -- ");
	str = ft_strjoin(str, &c);
	str = ft_strjoin(str, "\nusage: ft_ls [-ARSTUacdfglprtu1] [file ...]");
	ft_putendl_fd(str, 2);
}

int		check_nb_options(int argc, char **argv)
{
	int	i;
	int	nb;

	i = 1;
	nb = 0;
	if (argc > 1)
	{
		while (argv[i])
		{
			if (argv[i][0] == '-' && argv[i][1] && argv[i][1] == '-')
				return (nb);
			if (argv[i][0] == '-' && argv[i][1] && argv[i][1] != '-')
				nb++;
			else
				return (nb);
			i++;
		}
	}
	else
		nb = 0;
	return (nb);
}

char	**split_for_check_argv(int i, int j, char **tab, char **argv)
{
	if (argv[i])
	{
		while (argv[i])
		{
			tab[j] = argv[i];
			j++;
			i++;
		}
		tab[j] = '\0';
	}
	else
	{
		tab[0] = ".";
		tab[1] = '\0';
	}
	return (tab);
}

char	**check_argv(int argc, char **argv)
{
	int		i;
	int		j;
	int		nb;
	int		temp;
	char	**tab;

	nb = check_nb_options(argc, argv);
	tab = malloc(sizeof(char *) * argc - nb);
	i = 1;
	j = 0;
	temp = 0;
	while (argv[i] && argv[i][0] == '-' && argv[i][1] && !temp)
	{
		if (!ft_strcmp(argv[i], "--"))
			temp = 1;
		i++;
	}
	tab = split_for_check_argv(i, j, tab, argv);
	return (tab);
}

char	*treat_option_big_f(char *print, char *path)
{
	struct stat type;

	if (lstat(path, &type) == 0)
	{
		if (S_ISFIFO(type.st_mode))
			print = ft_strjoin(print, "|");
		if (S_ISDIR(type.st_mode))
			print = ft_strjoin(print, "/");
		if (S_ISLNK(type.st_mode))
			print = ft_strjoin(print, "@");
		if (S_ISSOCK(type.st_mode))
			print = ft_strjoin(print, "=");
		else if (!S_ISDIR(type.st_mode) && !S_ISLNK(type.st_mode) && (S_IXUSR
		& type.st_mode || S_IXGRP & type.st_mode || S_IXOTH & type.st_mode))
			print = ft_strjoin(print, "*");
	}
	return (print);
}
