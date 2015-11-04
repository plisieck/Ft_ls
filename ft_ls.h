/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 12:52:48 by plisieck          #+#    #+#             */
/*   Updated: 2015/01/18 12:53:25 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "./libft/libft.h"
# include <uuid/uuid.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/stat.h>
# include <string.h>
# include <stdlib.h>
# include <dirent.h>
# include <errno.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <sys/acl.h>

void	print_option_error(char c);
char	**check_argv(int argc, char **argv);
int		check_nb_options(int argc, char **argv);
int		check_if_is_file(char *file);
int		check_errors(char **files);
int		split_for_check_errors(char **files, DIR **dir);
char	***treat_option_r(char ***original_tab);
char	*treat_option_big_f(char *print, char *path);
void	simple_print(char ***tab, char **files, int *m, int *opt);
void	print_long_format_for_file(char **reads, int *opt);
char	*right_align(char *str, unsigned int max);
char	*left_align(char *str, unsigned int max);
int		check_max_nlink(char **str, char *files);
int		check_max_pwuid(char **str, char *files);
int		check_max_gruid(char **str, char *files);
int		check_max_size(char **str, int *k, char *files);
int		check_max_major(char **str, char *files);
int		check_max_minor(char **str, char *files);
char	*put_date_of_last_access(struct stat type, char *print, int *opt);
char	*put_date_of_data(struct stat type, char *print, int *opt);
char	*put_date_of_creation(struct stat type, char *print, int *opt);
char	*put_type(struct stat type);
char	*put_user_rights(struct stat type);
char	*put_group_rights(struct stat type);
char	*put_others_rights(struct stat type);
char	*put_rights(struct stat type);
char	*put_attr(char *path, struct stat type);
char	*put_owner_name(struct stat type, char *print, int max_pwuid);
char	*put_group_name(struct stat type, char *print, int max_gruid);
char	*put_number_of_links(struct stat type, char *print, int max_nlink);
char	*put_size(struct stat type, char *print, int *tab);
char	*put_major(struct stat type, char *print, int max_major);
char	*put_minor(struct stat type, char *print, int max_minor);
char	*put_date_of_last_modification(struct stat type, char *print, int *opt);
char	*put_pathname(char *path, char *name, char *print);
void	tri_stat(char ***reads, char **files);
void	tri_stat_big_u(char ***reads, char **files);
void	tri_stat_c(char ***reads, char **files);
void	tri_stat_u(char ***reads, char **files);
void	tri_stat_s(char ***reads, char **files);
void	print_long_format(char ***reads, char **files, int *opt);
void	select_options(int *opt, char ***readdir, char **files, int *k);
int		*check_max_lengths(char **reads, int z, char *files);
int		*split_check_max_lengths(char **reads, char *files, int *tab, int k);
int		split_for_main(int *opt, char **argv, int argc, char **params);
void	check_options(int *tab, char **argv);
void	split_for_recurssive(char **params, int i, int *opt, int multi_dir);
void	split_simple_files(char **files, int *opt, int i, int *k);
void	split_simple_files_two(char **files, int *opt, int i);
void	split_simple_files_three(int *opt, char **files);
DIR		**split_simple_files_four(char **files);
int		*split_long_format_file(char **reads, int *opt);
void	print_long_for_file2(char *reads_i, int *opt, int *tab, char *print);
void	split_check_option(int *tab, char **argv, int i, int j);
int		split_check_option2(int *tab, char **argv, int i, int j);
int		split_check_option3(int *tab, char **argv, int i, int j);
int		split_check_option4(int *tab, char **argv, int i, int j);
int		split_check_option5(int *tab, char **argv, int i, int j);
int		check_simple_files(char **files, int *opt);
void	split_check_readdir(char **files, DIR **dir, int i, int j);
int		*split_long_format_file2(char ***reads, int *opt);
void	treat_option_recursiv(char *params, int *opt, int multi_dir);
void	checks_for_recursive(char **params, int *opt);
void	eighth_for_big_r(char **tab, char *params, int *opt, int multi_dir);
void	seventh_for_big_r(int *opt, DIR *dir, char *params, int multi_dir);
void	fifth_split_for_big_r(int *opt, char **tab, char *params);
void	sixth_for_big_r(int *opt, char ***tab3, char **params3, char **tab);
void	fourth_split_for_big_r(char *params, int *opt, char **tab);
char	**third_split_for_big_r(int i, int *opt, char *params, int j);
int		second_split_for_big_r(char *params, int multi_dir, int *opt);
int		first_split_for_big_r(char *params, int *opt);
char	***first_check_readdir(DIR **dir, char **files, int *opt, char ***tab);
char	***third_check_readdir(int*i_j, char ***tab, struct dirent *lecture);
char	***second_check_readdir(int *i_j, char ***tab, int *opt, DIR **dir);
char	***check_readdir(char **files, int *opt);
void	split_tri_stat(char ***reads, char **files, int i, int j);
void	tri_stat(char ***reads, char **files);
void	split_tri_stat_big_u(char ***reads, char **files, int i, int j);
void	tri_stat_big_u(char ***reads, char **files);
void	split_tri_stat_c(char ***reads, char **files, int i, int j);
void	tri_stat_c(char ***reads, char **files);
void	split_tri_stat_u(char ***reads, char **files, int i, int j);
void	tri_stat_u(char ***reads, char **files);
void	split_tri_stat_s(char ***reads, char **files, int i, int j);
void	tri_stat_s(char ***reads, char **files);
void	split_for_plg(int *opt, char ***reads, int *tab, char **files);
int		*first_split_for_plg(char ***reads);
char	*second_split_for_plg(struct stat type, char *print);
void	another_for_big_r(char **tab4, int *opt, int multi_dir);
int		little_for_main(char **params);
char	**gestion_params(char **params);
int		split_gestion_params(char **params);
int		another_split_for_check_errors(char **files, int i, int k);
int		split_for_check_recursive(char **params, DIR **dir);

#endif
