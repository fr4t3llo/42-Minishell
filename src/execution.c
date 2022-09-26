/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:22:44 by skasmi            #+#    #+#             */
/*   Updated: 2022/09/26 22:37:55 by skasmi           ###   ########.fr       */
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

    tmp = lst;
	if (lst->next == NULL)
		if (ft_bulletin(lst->cmd, g_var.env))
			return ;
    while (tmp)
    {
		if (tmp->next)
			pipe(fd);
		pid = fork();
		if (pid < 0)
			printf("\033[31mdefault msg error should be here\n");
		if (pid == 0)
		{
			if (tmp->next)
			{
				dup2(fd[1], 1);
				close(fd[1]);
				close(fd[0]);
			}
        	ft_execution(tmp->cmd);
			printf("\033[31mcommand not found\n");
			exit (127);
		}
		else
		{
			wait(NULL);
			if (tmp->cmd)
			{
				dup2(fd[0], 0);
				close(fd[0]);
				close(fd[1]);
			}
		}
        tmp = tmp->next;
    }    
}

void    ft_execution(char   *cmd)
{
    char **single_path;
	int		i;
	char	**ptr;

	i = -1;
	single_path = ft_split(getenv("PATH"), ':');
    
	ptr = ft_split(cmd, ' ');

	while (single_path[++i])
	{
    	execve(ft_strjoin(ft_strjoin(single_path[i], "/"), ptr[0]), ptr, ft_get_env2());
	}
}
