/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_aux_functions1.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:50:42 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/22 05:46:15 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_get_args_and_red(char *cmd,
		t_pipe **lst_of_args, t_redic **lst_of_red)
{
	t_pipe	*tmp;
	int		i;

	i = 0;
	tmp = *lst_of_args;
	while (cmd[i])
	{
		if (cmd[i] == '>' || cmd[i] == '<')
			ft_get_red(cmd, &i, lst_of_red);
		else if (cmd[i] != ' ')
			ft_get_args(cmd, lst_of_args, &i);
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
		return (NULL);
	add_garbage(args);
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

void	errno_err(char *ptr)
{
	if (errno == 2)
	{
		ft_puterror(ptr, ": No such file or directory\n");
		exit (126);
	}
	else if (errno == 13)
	{
		ft_puterror(ptr, ":Permission denied\n");
		exit (126);
	}
	else if (errno == 13)
	{
		ft_puterror(ptr, ":Permission denied\n");
		exit (126);
	}
}
