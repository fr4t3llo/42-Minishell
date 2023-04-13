/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 00:33:57 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/22 05:45:41 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_to_lexer(t_lexm **lst, char *content)
{
	t_lexm	*tmp;

	tmp = *lst;
	if (!*lst)
		*lst = new_lexer(content);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_lexer(content);
	}
}

int	token(char *cmd)
{
	if (cmd[0] == '>')
	{
		if (cmd[1] == '>')
			return (APPEND);
		return (RED_OUT);
	}
	else if (cmd[0] == '<')
	{
		if (cmd[1] == '<')
			return (HEREDOC);
		return (RED_IN);
	}
	else if (cmd[0] == '|')
		return (PIPE);
	return (WORD);
}

t_lexm	*new_lexer(char *content)
{
	t_lexm	*node;

	node = (t_lexm *)malloc(sizeof(t_lexm));
	if (!node)
		return (0);
	add_garbage(node);
	node->cmd = content;
	node->type = token(content);
	node->next = NULL;
	return (node);
}
