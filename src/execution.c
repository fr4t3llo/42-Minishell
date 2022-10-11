/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:22:44 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/11 16:52:04 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char **ft_get_env2(void)
{
	int i;
	char	**ptr;

	i = 0;
	t_env *tmp;
	tmp = g_var.env;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	tmp = g_var.env;
	i = 0;
	ptr = (char **)malloc(sizeof(char *) * (i + 1));
	if (!ptr)
		return (NULL);
	while (tmp)
	{
		ptr[i++] = ft_strjoin(ft_strjoin(tmp->data, "="), tmp->value);
		tmp = tmp->next;
	}
	ptr[i] = NULL;
	return (ptr);
}

void    ft_start_exe(t_pipe *lst)
{
    t_pipe *tmp;
	int		fd[2];
	int		pid;
	int		status;

    tmp = lst;
	if (lst->next == NULL)
		if (ft_bulletin(lst->cmd))
			return ;
    while (tmp)
    {
		if (tmp->next)
			pipe(fd);
		pid = fork();
		if (pid < 0)
		{
			ft_puterror("fork", ": Resource temporarily unavailable\n");
			// set 1 global varibal status here
			return ;	
		}
		if (pid == 0)
		{
			if (tmp->next)
			{
				dup2(fd[1], 1);
				close(fd[1]);
				close(fd[0]);
			}
        	ft_execution(tmp->cmd);
		}
		if (tmp->next)
		{
			dup2(fd[0], 0);
			close(fd[0]);
			close(fd[1]);
		}
		else
			close (0);
    	tmp = tmp->next;
	}
	while (1)
		if (waitpid(-1, &status, 0) == -1)
			break;
	// chaeck status using macros here
}

void	ft_get_args_and_red(char *cmd, t_pipe **lst_of_args, t_redic **lst_of_red)
{
	t_pipe	*tmp;
	int		i;
	int		j;
	char	c;
	
	i = 0;
	tmp = *lst_of_args;
	while (cmd[i])
	{
		if (cmd[i] == '>' || cmd[i] == '<')
		{
			c = cmd[i];
			i++;
			if (cmd[i] == c)
			{
				i++;
				c = 'a';
			}
			while (cmd[i] && cmd[i] == ' ')
				i++;
			j = i;
			while (cmd[i] && !ft_strchr(" ><", cmd[i]))//  cmd[i] != ' ')
				i++;
			if (cmd[i])
				i--;
			ft_lstadd_back_red(lst_of_red, ft_substr(cmd, j, i - j + 1), c);
		}
		else if (cmd[i] != ' ')
		{
			j = i;
			while (cmd[i] && cmd[i] != ' ' && cmd[i] != '>' && cmd[i] != '<')
			{
				if (cmd[i] && ( cmd[i] == '\"' || cmd[i] == '\''))
				{
					c = cmd[i];
					i++;
					while (cmd[i] && ( cmd[i] != c))
						i++;
				}
				i++;
			}
			ft_lstadd_back(lst_of_args, ft_substr(cmd, j, i - j));
		}
		i++;
	}
}

int	size_of_lst(t_pipe *lst_of_args)
{
	t_pipe	*tmp;
	int		i;

	i = 0;
	tmp = lst_of_args;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

char	**args_lst_to_tab(t_pipe *lst_of_args)
{

	int		len;
	char	**args;
	t_pipe	*tmp;
	int		i;
	
	len = size_of_lst(lst_of_args);
	args = (char **)malloc(sizeof(char *) * (len + 1));
	if (!args)
		return NULL;
	i = 0;
	tmp = lst_of_args;
	while (tmp)
	{
		args[i++] = tmp->cmd;	
		tmp = tmp->next;
	}
	args[i] = NULL;
	return (args);
}

void	ft_puterror(char *err, char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(err, 2);
	ft_putstr_fd(msg, 2);
}

void    ft_execution(char   *cmd)
{
	t_pipe	*lst_of_args;
	t_redic	*lst_of_red;
    char **single_path;
	char	**ptr;
	int		i;
	
	lst_of_args = NULL;
	lst_of_red	= 	NULL;
	ft_get_args_and_red(cmd, &lst_of_args, &lst_of_red);

	// protect if not cmd
	
	ptr = args_lst_to_tab(lst_of_args);
	i = -1;

	if (lst_of_red)
		run_rediction(lst_of_red);

	ft_convert_to_lower(ptr[0]);
	single_path = ft_split(getenv("PATH"), ':');
	while (single_path[++i])
    	execve(ft_strjoin(ft_strjoin(single_path[i], "/"), ptr[0]), ptr, ft_get_env2());

	ft_puterror(ptr[0], ":command not found\n");
	exit (127);
}
