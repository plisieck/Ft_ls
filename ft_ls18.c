/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls18.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 15:07:26 by plisieck          #+#    #+#             */
/*   Updated: 2015/01/17 17:41:34 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*put_minor(struct stat type, char *print, int max_minor)
{
	char *str;

	str = ft_strjoin(print, right_align(ft_itoa
				(type.st_rdev & 255), max_minor));
	return (str);
}

char	*put_size(struct stat type, char *print, int *tab)
{
	char *str;

	if (print[0] == 'b' || print[0] == 'c')
	{
		str = put_major(type, print, tab[4]);
		str = put_minor(type, str, tab[5]);
	}
	else
	{
		if (tab[4])
			str = ft_strjoin(print, right_align(ft_itoa(type.st_size),
			tab[4] + tab[5] + 3));
		else
			str = ft_strjoin(print, right_align(ft_itoa(type.st_size),
			tab[3] + tab[5]));
	}
	str = ft_strjoin(str, " ");
	return (str);
}

void	another_for_big_r(char **tab4, int *opt, int multi_dir)
{
	int			x;
	struct stat type;
	char		*path;

	x = 0;
	while (tab4[x])
	{
		lstat(tab4[x], &type);
		if (S_ISDIR(type.st_mode))
		{
			path = ft_strrchr(tab4[x], '/');
			path++;
			if (path[0] != '.' || opt[2])
			{
				ft_putchar('\n');
				ft_putendl(ft_strjoin(tab4[x], ":"));
				treat_option_recursiv(tab4[x], opt, multi_dir);
			}
		}
		x++;
	}
}

int		little_for_main(char **params)
{
	int	i;
	int	k;

	i = -1;
	k = 0;
	while (params[++i])
		k++;
	return (k);
}

int		split_gestion_params(char **params)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (params[i])
	{
		if (opendir(params[i]))
			k++;
		i++;
	}
	return (k);
}
