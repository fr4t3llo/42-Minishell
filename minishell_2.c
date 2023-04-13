/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:11:02 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/21 16:11:15 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_new_env(char **env)
{
	t_env	**new_env;
	char	**splt;
	int		i;

	g_var.env = NULL;
	new_env = &g_var.env;
	i = 0;
	while (env[i])
	{
		splt = ft_split(env[i], '=');
		ft_lst_addback_env(new_env, ft_lstnew_env(splt[0], splt[1]));
		i++;
	}
}

void	only_export(void)
{
	t_env	*env;

	env = g_var.env;
	while (env)
	{
		if (env->value)
			printf("declare -x %s=\"%s\"\n", env->data, env->value);
		else
			printf("declare -x %s\n", env->data);
		env = env->next;
	}
}

int	ft_bulletin_2(char **ptr)
{
	if (ft_strcmp(ptr[0], "pwd") == 0)
		return (ft_pwd(ptr), 1);
	if (ft_strcmp(ptr[0], "exit") == 0)
		return (ft_exit(ptr), 1);
	else if (ft_strcmp(ptr[0], "echo") == 0)
		return (ft_echo(ptr), 1);
	else if (ft_strcmp(ptr[0], "cd") == 0)
		return (ft_cd(ptr), 1);
	else if (ft_strcmp(ptr[0], "env") == 0)
		return (ft_env(), 1);
	else if (ft_strcmp(ptr[0], "unset") == 0)
		return (ft_unset_more_then_one(ptr), 1);
	else if (ft_strcmp(ptr[0], "export") == 0)
	{
		if (!ptr[1])
			return (only_export(), 1);
		return (ft_export(ptr), 1);
	}
	return (0);
}

int	ft_bulletin(char *cmd)
{
	t_pipe	*lst_of_args;
	t_redic	*lst_of_red;
	char	**ptr;

	lst_of_args = NULL;
	lst_of_red = NULL;
	ft_get_args_and_red(cmd, &lst_of_args, &lst_of_red);
	if (lst_of_red)
		run_rediction(lst_of_red);
	if (!lst_of_args)
		return (0);
	ptr = args_lst_to_tab(lst_of_args);
	ft_convert_to_lower(ptr[0]);
	return (ft_bulletin_2(ptr));
}

int	only_space(char *cmd)
{
	int	i;

	i = -1;
	while (cmd[++i])
	{
		if (cmd[i] != ' ')
			return (0);
	}
	return (1);
}
