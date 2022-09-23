/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:43:42 by skasmi            #+#    #+#             */
/*   Updated: 2022/09/23 23:05:19 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ********************* stock all env in table 2D called env_var *************
char	**copy_envs(char **env)
{
	int		nb_of_line;
	int		nb_for_alloc;
	char	**env_var;

	nb_of_line = 0;
	nb_for_alloc = 0;
	while (env[nb_of_line])
	{
		nb_for_alloc = strlen(env[nb_of_line]);
		env_var = (char **)malloc(sizeof(char) * nb_for_alloc);
		if (!env_var)
			return (NULL);
		nb_of_line++;
		nb_for_alloc++;
	}
	nb_of_line = 0;
	nb_for_alloc = 0;
	while (env[nb_of_line])
	{
		env_var[nb_for_alloc] = env[nb_of_line];
		nb_for_alloc++;
		nb_of_line++;
	}
	return (env_var);
}

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
	if(ft_syntax_general(cmd) == 0)
			printf("\033[31mMinishell : syntax error !!!\n\033[37m");
	if (ft_strcmp(ft_execute_bulletin(cmd), "exit") == 0)
		ft_exit(cmd);
	if (ft_strcmp(ft_execute_bulletin(cmd), "pwd") == 0)
		ft_pwd(cmd);
	if (ft_strcmp(ft_execute_bulletin(cmd), "cd") == 0)
		ft_cd(cmd);
	if (ft_strcmp(ft_execute_bulletin(cmd), "env") == 0)
		ft_env(t);
}

void	handle_signal(int sig)
{
	(void)sig;
	printf("FRATELLO😈=>\n");
}

int	main(int ac, char **av, char **env)
{
	char	*cmd;
	t_env	*list_env;

	(void) ac;
	(void) av;
    // char **nothing = NULL;
	list_env = ft_new_env(env);
    // struct sigaction sa;
    // sa.sa_handler = &handle_signal;
    // sa.sa_flags = SA_RESTART;
    // sigaction(SIGINT, &sa, NULL);
	while (1)
	{
		cmd = readline("\033[37mFRATELLO😈=> ");
		if (!cmd)
			break ; // free allocated memory
		if (cmd[0] == '\0')
		{
			free(cmd);
			continue;
		}
		ft_bulletin(cmd, list_env);
		add_history(cmd);
        // if (sigaction(SIGINT, &sa, NULL) == 1)
        // {
        //     printf("wa hya sidi rebi\n");
        //     continue;
        // }
		// ft_expand(cmd);
        // nothing = ft_split(cmd, ' ');
        // if (ft_strcmp(nothing[0], "") == 0)
        //     continue;
        // // if (ft_strcmp(cmd, "export") == 0)
        // //     ft_export(list_env);
		
	}
	return (0);
}
