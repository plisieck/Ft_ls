/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 20:13:59 by plisieck          #+#    #+#             */
/*   Updated: 2015/01/12 19:33:40 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		split_check_option2(int *tab, char **argv, int i, int j)
{
	if (argv[i][j] == 'l' && !tab[16])
		return (tab[0] = 1);
	else if (argv[i][j] == 'R' && !tab[16])
		return (tab[1] = 1);
	else if (argv[i][j] == 'a' && !tab[16])
		return (tab[2] = 1);
	else if (argv[i][j] == 'r' && !tab[16])
		return (tab[3] = 1);
	else if (argv[i][j] == 't' && !tab[16])
		return (tab[4] = 1);
	else if (argv[i][j] == 'g' && !tab[16])
	{
		tab[0] = 1;
		return (tab[6] = 1);
	}
	else if (argv[i][j] == 'A' && !tab[16])
		return (tab[7] = 1);
	else if (argv[i][j] == 'd' && !tab[16])
		return (tab[8] = 1);
	return (0);
}

int		split_check_option3(int *tab, char **argv, int i, int j)
{
	if (argv[i][j] == 'p' && !tab[16])
	{
		tab[18] = 0;
		return (tab[9] = 1);
	}
	else if (argv[i][j] == 'S' && !tab[16])
		return (tab[11] = 1);
	else if (argv[i][j] == 'U' && !tab[16])
	{
		tab[10] = 0;
		tab[11] = 0;
		tab[13] = 0;
		return (tab[12] = 1);
	}
	else if (argv[i][j] == 'c' && !tab[16])
	{
		tab[10] = 0;
		return (tab[13] = 1);
	}
	else if (argv[i][j] == '-' && !argv[i][j + 1] &&
			argv[i][j - 1] == '-' && !tab[16])
		return (tab[16] = 1);
	return (0);
}

int		split_check_option5(int *tab, char **argv, int i, int j)
{
	if (argv[i][j] == 'u' && !tab[16])
	{
		tab[13] = 0;
		return (tab[10] = 1);
	}
	else if (argv[i][j] == 'f' && !tab[16])
	{
		tab[2] = 1;
		return (tab[14] = 1);
	}
	return (0);
}

int		split_check_option4(int *tab, char **argv, int i, int j)
{
	if (argv[i][j] == 'T' && !tab[16])
		return (tab[15] = 1);
	else if (argv[i][j] == '1' && !tab[16])
	{
		tab[0] = 0;
		return (1);
	}
	else if (argv[i][j] == 'o' && !tab[16])
	{
		tab[0] = 1;
		return (tab[17] = 1);
	}
	else if (argv[i][j] == 'F' && !tab[16])
	{
		tab[9] = 0;
		return (tab[18] = 1);
	}
	return (0);
}

void	split_check_option(int *tab, char **argv, int i, int j)
{
	while (argv[i][j])
	{
		if (!(split_check_option2(tab, argv, i, j)))
		{
			if (!(split_check_option3(tab, argv, i, j)))
			{
				if (!(split_check_option4(tab, argv, i, j)))
				{
					if (!(split_check_option5(tab, argv, i, j)))
					{
						print_option_error(argv[i][j]);
						tab[5] = -1;
						return ;
					}
				}
			}
		}
		j++;
	}
}
