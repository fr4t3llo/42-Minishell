/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:22:44 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/22 05:45:05 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	main_exc(t_pipe *lst)
{
	t_pipe	*tmp;
	int		fd[2];
	int		pid;

	tmp = lst;
	while (tmp)
	{
		if (tmp->next)
			pipe(fd);
		pid = fork();
		if (pid < 0)
			return (fork_resource());
		if (pid == 0)
			sub_main(tmp, fd);
		if (tmp->next)
			dup_0(fd);
		else
		{
			g_var.pid = pid;
			close(0);
		}
		tmp = tmp->next;
	}
}

void	ft_start_exe(t_pipe *lst)
{
	if (lst->next == NULL)
		if (ft_bulletin(lst->cmd))
			return ;
	main_exc(lst);
	get_status();
}

void	exuc_cmd(char **ptr)
{
	char	**single_path;
	int		i;

	if (ft_strchr(ptr[0], '/'))
	{
		if (!access(ptr[0], F_OK | X_OK))
		{
			execve(ptr[0], ptr, ft_get_env2());
			exit (0);
		}
		errno_err(ptr[0]);
	}
	else
	{
		if (get_from_env("PATH"))
		{
			single_path = ft_split(get_from_env("PATH"), ':');
			i = -1;
			while (single_path[++i])
				execve(ft_strjoin(ft_strjoin(single_path[i], "/"),
						ptr[0]), ptr, ft_get_env2());
		}
		ft_error_and_exit(&ptr[0]);
	}
}

void	ft_error_and_exit(char **ptr)
{
	ft_puterror(ptr[0], ":command not found\n");
	exit(127);
}

void	ft_execution(char *cmd)
{
	t_pipe	*lst_of_args;
	t_redic	*lst_of_red;
	char	**ptr;

	lst_of_args = NULL;
	lst_of_red = NULL;
	ft_get_args_and_red(cmd, &lst_of_args, &lst_of_red);
	if (!lst_of_args)
		exit (0);
	ptr = args_lst_to_tab(lst_of_args);
	if (lst_of_red)
		run_rediction(lst_of_red);
	ft_convert_to_lower(ptr[0]);
	exuc_cmd(ptr);
}
