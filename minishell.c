/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:43:42 by skasmi            #+#    #+#             */
/*   Updated: 2022/09/25 23:38:59 by skasmi           ###   ########.fr       */
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
		free(splt);
	}
	return (new_env_list);
}

void	ft_bulletin(char *cmd, t_env *t)
{
	if (ft_strcmp(ft_execute_bulletin(cmd), "exit") == 0)
		ft_exit(cmd);
	if (ft_strcmp(ft_execute_bulletin(cmd), "pwd") == 0)
		ft_pwd(cmd);
	if (ft_strcmp(ft_execute_bulletin(cmd), "cd") == 0)
		ft_cd(cmd);
	if (ft_strcmp(ft_execute_bulletin(cmd), "env") == 0)
		ft_env(t);
}

int	main(int ac, char **av, char **env)
{
	char	*cmd;
	t_env	*list_env;
	char	**pipe;

	(void) ac;
	(void) av;
	list_env = ft_new_env(env);
	int n = 0;
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
		{
			free(cmd);
			continue;
		}
		if (ft_syntax_general(cmd) == 1)
			printf("\033[31mMinishell : syntax error !!!\n\033[37m");
		else
		{
			pipe = ft_pipe(cmd);
			while (n < 10)
			{
				printf("%s\n", pipe[n]);
				n++;
			}
			ft_bulletin(cmd, list_env);
		}
	}
	return (0);
}
