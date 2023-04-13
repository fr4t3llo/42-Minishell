/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:02:48 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/22 01:37:17 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_convert_to_lower(char *cmd)
{
	int	i;

	i = 0;
	while (*cmd)
	{
		if (*cmd >= 'A' && *cmd <= 'Z')
			*cmd += 32;
		cmd++;
	}
}

void	pass_or_not(char *cmd)
{
	cmd = check_heredoc(cmd);
	if (cmd == NULL)
	{
		ft_putstr_fd("\033[31mMinishell : syntax error !!!\n\033[37m", 2);
		return ;
	}
	if (g_var.doc == 1)
		g_var.doc = 0;
	else
		ft_pipe(cmd);
}

char	*check_heredoc(char *cmd)
{
	t_lexm	*here;
	t_lexm	*tmp;

	here = ft_lexer(cmd);
	tmp = here;
	while (tmp)
	{
		if (tmp->type == HEREDOC)
		{
			if (tmp->next == NULL || tmp->next->type != WORD)
				return (NULL);
		}
		tmp = tmp->next;
	}
	ft_run_heredoc(&here);
	return (lexter_to_string(here));
}
