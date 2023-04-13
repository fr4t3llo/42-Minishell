/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:43:42 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/22 03:00:33 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_run_heredoc(t_lexm **lexer)
{
	g_var.doc = 0;
	signal(SIGINT, handler);
	rl_event_hook = event;
	main_heredoc(lexer);
}

void	ft_start(int fd[2])
{
	char	*cmd;

	while (1)
	{
		g_var.doc = 0;
		cmd = readline("FRATELLO😈=> ");
		add_garbage(cmd);
		if (!cmd)
			break ;
		if (cmd[0] == '\0' || only_space(cmd))
			continue ;
		add_history(cmd);
		if (ft_syntax_general(cmd) == 1)
		{
			cmd = check_heredoc(cmd);
			ft_putstr_fd("Minishell : syntax error !!!\n", 2);
		}
		else
			pass_or_not(cmd);
		dup2(fd[0], 0);
		dup2(fd[1], 1);
	}
}

void	handle_sig(int pid)
{
	(void)pid;
	rl_replace_line("", 0);
	printf("\n");
	rl_on_new_line();
	rl_redisplay();
}

char	*ft_extratct_string_from_qutes(char *str)
{
	int		i;
	char	**ptr;
	char	c;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\'' || str[i] == '\"')
	{
		c = str[i];
		ptr = ft_split(str, c);
		i = 0;
		str = ft_strdup("");
		while (ptr[i])
		{
			str = ft_strjoin(str, ptr[i]);
			i++;
		}
	}
	return (str);
}

int	main(int ac, char **av, char **env)
{
	int		fd[2];

	fd[0] = dup(0);
	fd[1] = dup(1);
	(void)av;
	if (ac == 1)
	{	
		signal(SIGINT, handle_sig);
		signal(SIGQUIT, SIG_IGN);
		g_var.garbage = NULL;
		g_var.pwd = 1;
		g_var.oldpwd = 1;
		ft_new_env(env);
		ft_shllvl();
		ft_start(fd);
		close(fd[0]);
		close(fd[1]);
	}
	return (0);
}
