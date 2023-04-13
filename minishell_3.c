/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:12:55 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/21 21:40:32 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_unique_name(void)
{
	static int	nb;
	char		*fname;

	fname = ft_strjoin("/tmp/here_file_", ft_itoa(nb++));
	while (access(fname, F_OK) == 0)
		fname = ft_strjoin(fname, "m");
	return (fname);
}

int	here_loop(t_lexm *tmp, char *file_name, int fd)
{
	char		*line;

	line = readline("> ");
	add_garbage(line);
	if (!line || ft_strcmp(tmp->next->cmd, line) == 0 || g_var.doc)
	{
		tmp->cmd = "<";
		tmp->next->cmd = file_name;
		close (fd);
		return (1);
	}
	write (fd, ft_strjoin(line, "\n"), ft_strlen(line) + 1);
	return (0);
}

void	main_heredoc(t_lexm **lexer)
{
	char		*file_name;
	t_lexm		*tmp;
	int			fd;

	tmp = *lexer;
	while (tmp && !g_var.doc)
	{
		if (tmp->type == HEREDOC)
		{
			file_name = get_unique_name();
			fd = open(file_name, O_RDWR | O_CREAT, 0666);
			while (1)
			{
				if (here_loop(tmp, file_name, fd))
					break ;
			}
		}
		tmp = tmp->next;
	}
}

void	handler(int sig)
{
	(void)sig;
	g_var.doc = 1;
	rl_done = 1;
}

int	event(void)
{
	return (0);
}
