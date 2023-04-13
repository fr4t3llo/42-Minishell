/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:40:28 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/22 04:03:59 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_error_cmd(char **cmd)
{
	printf("%s: invalid option %c\n", cmd[0], cmd[1][1]);
	printf("cd: usage [without options] [dir]\n");
	return ;
}

void	ft_change_pwd_and_old(char *ptr, char *cwd)
{
	t_env	*t;

	t = g_var.env;
	if (errno == ENOENT)
	{
		perror("cd: error retrieving current directory: getcwd:\
				cannot access parent directories");
		return ;
	}
	if (get_from_env("OLDPWD") == NULL)
	{
		ft_aux_export(ft_strdup("OLDPWD"), cwd);
		return ;
	}
	while (t)
	{
		if (ft_strcmp(ptr, t->data) == 0)
		{
			t->value = cwd;
			return ;
		}
		t = t->next;
	}
}

void	ft_if_null_path(char *home)
{
	t_env	*t;

	t = g_var.env;
	home = get_from_env("HOME");
	if (!home)
	{
		ft_puterror("cd", ": HOME not set");
		write(1, "\n", 1);
		return ;
	}
	chdir(home);
	while (t)
	{
		if (ft_strcmp("PWD", t->data) == 0)
		{
			t->value = home;
			return ;
		}
		t = t->next;
	}
	return ;
}

void	ft_getcwd(void)
{
	char	*s;

	s = getcwd(NULL, 0);
	add_garbage(s);
	if (g_var.pwd)
		ft_change_pwd_and_old("PWD", s);
}

void	ft_cd(char **path)
{
	int		nb;
	t_env	*t;

	t = g_var.env;
	nb = 0;
	if (path[1] == NULL)
		return (ft_if_null_path(path[1]));
	if (!path || !*path || ft_strncmp(path[0], "cd", 255))
		return ;
	if (path[1] && path[1][0] == '-' && path[1][1] != '\0' && path[1][1] != '-')
		ft_error_cmd(path);
	else if (path[1])
	{
		if (g_var.oldpwd)
			ft_if_path();
		nb = chdir(path[1]);
	}
	if (nb < 0)
		perror("cd");
	else
		ft_getcwd();
	g_var.status = 0;
}
