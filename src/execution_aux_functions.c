/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_aux_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:47:53 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/22 05:44:34 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	get_status(void)
{
	int	status;
	int	status_2;

	waitpid(g_var.pid, &status, 0);
	while (1)
		if (waitpid(-1, &status_2, 0) == -1)
			break ;
	if (WIFEXITED(status))
		g_var.status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		if (status == 3)
			printf("^\\Quit: 3\n");
		g_var.status = 128 + WTERMSIG(status);
	}
}

void	dup_1(int fd[2])
{
	dup2(fd[1], 1);
	close(fd[1]);
	close(fd[0]);
}

void	dup_0(int fd[2])
{
	dup2(fd[0], 0);
	close(fd[0]);
	close(fd[1]);
}

void	fork_resource(void)
{
	ft_puterror("fork", ": Resource temporarily unavailable\n");
	g_var.status = 1;
}

void	sub_main(t_pipe *tmp, int fd[2])
{
	if (tmp->next)
		dup_1(fd);
	ft_execution(tmp->cmd);
}
