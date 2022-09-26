/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:43:42 by skasmi            #+#    #+#             */
/*   Updated: 2022/09/26 22:37:29 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_new_env(char **env)
{
	t_env	*new_env_list;
	char	**splt;
	int		i;

	new_env_list = NULL;

	i = 0;
	while (env[i])
	{
		splt = ft_split(env[i], '=');
		ft_lst_addback_env(&new_env_list, ft_lstnew_env(splt[0], splt[1]));
		i++;
	}
	return (new_env_list);
}

int	ft_bulletin(char *cmd, t_env *t)
{
	if (ft_strcmp(ft_execute_bulletin(cmd), "exit") == 0)
		return (ft_exit(cmd), 1);
	if (ft_strcmp(ft_execute_bulletin(cmd), "pwd") == 0)
		return (ft_pwd(cmd), 1);
	if (ft_strcmp(ft_execute_bulletin(cmd), "cd") == 0)
		return (ft_cd(cmd), 1);
	if (ft_strcmp(ft_execute_bulletin(cmd), "env") == 0)
		return (ft_env(t), 1);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	char	*cmd;
	int fd[2];

	fd[0] = dup(0);
	fd[1] = dup(1);
	(void) av;
	if (ac == 1)
	{
		g_var.env = ft_new_env(env);
		//int n = 0;
		while (1)
		{
			cmd = readline("\033[37mFRATELLO😈=> ");
			if (cmd)
			{
				add_history(cmd);
			}
			if (!cmd)
			 	break ; // free allocated memory
			if (cmd[0] == '\0')
				continue;
			if (ft_syntax_general(cmd) == 1)
				printf("\033[31mMinishell : syntax error !!!\n\033[37m");
			else
			{
				ft_pipe(cmd);
				/*while (n < 10)
				{
					printf("%s\n", pipe[n]);
					n++;
				}*/
			}
			dup2(fd[0], 0);
			dup2(fd[1], 1);
		}
		close(fd[0]);
		close(fd[1]);
	}
	return (0);
}
